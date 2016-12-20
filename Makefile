CC=g++
LIBS= -lcurl 

make: 
	$(CC) main.cpp EmotionQuery.cpp FaceEmotion.cpp $(LIBS) -o main

clean:
	rm main
