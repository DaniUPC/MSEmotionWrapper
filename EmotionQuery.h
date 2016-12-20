#ifndef EMOTION_QUERY_H
#define EMOTION_QUERY_H

#include <string.h>
#include <curl/curl.h>
#include <vector>
#include <rapidjson/document.h>
#include "FaceEmotion.h"

using namespace rapidjson;
using namespace std;

/*
 * 	Class to query the emotion of faces using the Microsoft Emotion API
 */

class EmotionQuery 
{

	private:
		
		const char* _ms_key;
		const char* _url;
		

	protected:

		// Parses the faces emotions from an input json content
		static vector<FaceEmotion> parse_json(const char* inp);
		
		// Parses a face emotion answer from the JSON object
		static FaceEmotion parse_face(Value::Object obj);
		
		// Handles reply from the REST server and writes into the given string
		static size_t handle_reply(void *contents, size_t size, size_t nmemb, string *s);


	public:

		// Initializes query with the url and the user key
		EmotionQuery(const char* url, const char* ms_key);
		
		// Sends the input content into the Microsoft Emotion API
		vector<FaceEmotion> send_query(const char* content, long size);

};
 

#endif // EMOTION_QUERY_H
