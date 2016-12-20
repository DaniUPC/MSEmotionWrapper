#include <iostream>
#include <vector>
#include "EmotionQuery.h"
#include "IOHelper.h"

using namespace std;


static void print_face(FaceEmotion& f)
{
	cout << "Got face with top emotion " << f.get_expression() << "\n" <<
		"\t - Position: (" << f.get_top() << ", " << f.get_left() << ")\n"
		"\t - Dimensions: (" << f.get_height() << ", " << f.get_width() << ")\n" <<
		"\t - Center: (" << f.get_center()[0] << "," << f.get_center()[1] << ")\n" << 
		"\t - Score: " << f.get_score() << endl;
} 


int main(int argc, char *argv[])
{

	const char* key = "ocp-apim-subscription-key: INSERT KEY HERE";
 	const char* url = "https://api.projectoxford.ai/emotion/v1.0/recognize";
	const char* file_name = "image.jpg";
 
	// Get bytes of file
	FileInfo body = read_bytes(file_name);
	
	// Initialize query
	EmotionQuery query = EmotionQuery(url, key);
	
	// Send file and gather expressions
	vector<FaceEmotion> emotions = query.send_query(body.content, body.size);
	
	// List faces
	for (int i = 0; i < emotions.size(); ++i)
	{
		print_face(emotions[i]);
	}

	return 0;
}

