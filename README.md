# MSEmotionWrapper
C++ wrapper to call Microsoft Emotion Services.

## Requirements

 This wrapper depends on the following libraries:
 
  - [Curl library](https://curl.haxx.se/)
  - [RapidJSON library](https://github.com/miloyip/rapidjson)
 
We have used the latest RapidJSON version and Curl 7.51.
 
## Use
 
We have provided a [Creative Commons test image](https://www.flickr.com/photos/micru/6154242982/in/photolist-anQ72C-pxXDTc-cT7vm3-cT7AaE-pQoTGg-pNii4m-cT7zs1-cT7y5U-cT7AQE-cT7ADC-pxU9Vk-pQt7p9-cT7yC7-cT7uEy-cT7yRS-cT7zb9-cT7xzo-oTAhgF-cT7uqu-oTAgpF-cT7B3f-oTAhQr-pxZGHu-9X1qtP-cT7Ar3-9X1qcH-pQt7dN-oTAgQv-pNicNb-cT7vyQ-cT7yky-cT7xo1-pQoMNH-cT7tWN-cT7sSs-cT7uTh-pQt7mU-cT7v9u-oTxg3f-anQ5Xj-cT7ubE-9X4h3f-cT7wqo-9X4hkA-pxWMbG-9X4gEL-anQ68W-cT7wVL-pxU9Cr-9X4h77) from Flickr. All credits of the image go to [mic-pic](https://www.flickr.com/photos/micru/).
 
 Modify the following line in [main.cpp](https://github.com/DaniUPC/MSEmotionWrapper/blob/master/main.cpp) so it uses your personal API key from Microsoft Cognitive Services:
 
 ```python
const char* key = "ocp-apim-subscription-key: INSERT KEY HERE";
```

If you do not have a key, you can get one [here](https://www.microsoft.com/cognitive-services/en-us/apis).

Then, inside the project folder:
 ```
 make
 ./main
```
