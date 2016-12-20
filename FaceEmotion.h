#ifndef FACE_MOTION_H
#define FACE_EMOTION_H

#include <string.h>
#include <stdexcept>
#include <rapidjson/document.h>

using namespace rapidjson;
using namespace std;


enum Expression 
{ 
	ANGER = 0, 
	CONTEMPT = 1, 
	DISGUST = 2, 
	FEAR = 3, 
	HAPPINESS = 4, 
	NEUTRAL = 5, 
	SADNESS = 6, 
	SURPRISE = 7
};


inline Expression from_string(const string& s)
{
	if (s.compare("anger") == 0)
	{
		return ANGER;
	} 
	else if (s.compare("contempt") == 0)
	{
		return CONTEMPT;
	}
	else if (s.compare("disgust") == 0)
	{
		return DISGUST;
	}
	else if (s.compare("fear") == 0)
	{
		return FEAR;
	}
	else if (s.compare("happiness") == 0)
	{
		return HAPPINESS;
	}
	else if (s.compare("neutral") == 0)
	{
		return NEUTRAL;
	}
	else if (s.compare("sadness") == 0)
	{
		return SADNESS;
	}
	else if (s.compare("surprise") == 0)
	{
		return SURPRISE;
	}
	else {
		throw invalid_argument("Value is not contained in the defined enum");
	}
}


class FaceEmotion
{

		private:
		
			Expression dominant;
			double confidence;

			int height;
			int width;
			int left;
			int top;

		public:
		
			/*
			 * 	Returns the (y,x) coordinates of the center of the face
			 */
			int *get_center();

			/*
			 * 	Parses the object from a JSON input
			 */ 
			void parseObject(Value::Object obj);
			
			
			/*
			 * 	List of getters
			 */ 
			int get_height();
			int get_width();
			int get_left();	// Left coordinates in image of face start
			int get_top();	// Top coordinate in image of face start	
			double get_score();
			Expression get_expression();
			
};
 

#endif // FACE_EMOTION_H
