#include "EmotionQuery.h"
#include <stdexcept>


EmotionQuery::EmotionQuery(const char* url, const char* ms_key)
{
	_url = url;
	_ms_key = ms_key;
}


vector<FaceEmotion> EmotionQuery::send_query(const char* inp, long size)
{

	CURL *curl;
	CURLcode res;
	struct curl_slist *headers=NULL;
	string answer;
	vector<FaceEmotion> emotions;

	// Start CURL content
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	if(curl) {
		
		// Define headers
		headers = curl_slist_append(headers, _ms_key);
		headers = curl_slist_append(headers, "Content-Type: application/octet-stream");

		// Configure query
		curl_easy_setopt(curl, CURLOPT_URL, _url); // URL
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers); // Headers
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, inp); // What to send
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, size); // Size of body
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_reply);	// How to gather results
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &answer);	 // Where to store results
    
		// Send request
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			throw runtime_error(string("Query failedurl_easy_perform() failed: ") 
				+ string(curl_easy_strerror(res)) + string("\n"));
		}

		// Parse response into emotions
	 	emotions = parse_json(answer.c_str());	
	}
	else
	{
		throw std::runtime_error("Curl could not be initialized");
	}
		
    // Clean curl and headers
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    
    return emotions;
}


vector<FaceEmotion> EmotionQuery::parse_json(const char* inp)
{
	vector<FaceEmotion> faces;

	// Parse JSON and makes sure it comes as an array
	Document d;
	d.Parse(inp);
	assert(d.IsArray());

	// Each element is the output of a face
	for(SizeType i = 0; i < d.Size(); ++i) {
		Value::Object face = d[i].GetObject();
		faces.push_back(parse_face(face));	
	}

	return faces;
}
	
	
FaceEmotion EmotionQuery::parse_face(Value::Object obj)
{
	FaceEmotion f = FaceEmotion();
	f.parseObject(obj);
	return f;	
}
	

size_t EmotionQuery::handle_reply(void *contents, size_t size, size_t nmemb, string *s)
{
	// Compute length of the message
    size_t new_length = size*nmemb;
    size_t old_length = s->size();

	// Resize string to fit new length
    try
    {
        s->resize(old_length + new_length);
    }
    catch(std::bad_alloc &e)
    {
        return 0;
    }

	// Append contents into the output string
    std::copy((char*)contents, 
				(char*)contents + new_length,
				s->begin() + old_length);

	// Return size of the read content
    return size*nmemb;
}

