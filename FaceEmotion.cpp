#include "FaceEmotion.h"


int* FaceEmotion::get_center()
{
	// Returns the aprox coordinates (y, x) of the detected face's center
	int* center = new int[2];
	center[0]	= top + (height/2);
	center[1] = left + (width/2);
	return center;
}


void FaceEmotion::parseObject(Value::Object obj)
{
	assert(obj.HasMember("faceRectangle"));
	assert(obj.HasMember("scores"));

	// Parse positions
	Value::Object location = obj["faceRectangle"].GetObject();
	height = location["height"].GetInt();
	width = location["width"].GetInt();
	left = location["left"].GetInt();
	top = location["top"].GetInt();

	// Get emotion with higher score
	const Value& scores = obj["scores"];
	double max = -1;
	Expression emotion = ANGER;
	for (Value::ConstMemberIterator itr = scores.MemberBegin();
				itr != scores.MemberEnd(); ++itr)
	{
		Expression current_expr = from_string(itr->name.GetString());
		double score = itr->value.GetDouble();
		if (score > max)
		{
			max = score;
			emotion = current_expr;
		}
	}

	// Set attributes
	dominant = emotion;
	confidence = max;
}


int FaceEmotion::get_height()
{
	return height;
}


int FaceEmotion::get_width()
{
	return width;
}


int FaceEmotion::get_left()
{
	return left;
}
	

int FaceEmotion::get_top()
{
	return top;
}


double FaceEmotion::get_score()
{
	return confidence;
}


Expression FaceEmotion::get_expression()
{
	return dominant;
}


