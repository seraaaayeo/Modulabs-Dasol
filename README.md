# AIFFEL Basic 여다솔방 자료
[모두의연구소 X sba 아카데미] 아이펠 기본과정 여다솔방 실습자료 및 추가자료, 개인 정리 노트

## 오늘의 자료
### 11/25 수요일
[F-28] CNN based pre-trained model : [VGG, ResNet 실습]()
* VGG, GoogLeNet, AlexNet, ResNet 등은 2010년 이후 ImageNet Challenge에서 등장한 CNN 기반의 모델이라고 설명드렸습니다. 이처럼 이미 만들어진 네트워크들이 다양하게 공개되어 있는데요, 이를 `pre-trained model`이라고 합니다. Pre-trained model은 `keras` 등을 이용하여 import하여 사용할 수 있습니다. 이 중 `VGG16`와 `ResNet-50`을 직접 구현하여 연습해봅시다.
* 이러한 Deep Network들은 용어 그대로 **Deep**하며 파라미터 또한 굉장히 많습니다. 이를 CPU로 학습시키려면 시간이 무지 오래 걸려요...! [`Tensorflow-gpu`를 사용 가능한지 체크해보세요!](./Check_tf_gpu.ipynb)

## 지난 자료들
### 10/28 수요일
[F-18] Pillow와 OpenCV로 이미지 처리하기
* `OpenCV`를 이용하여 노트북 웹캠으로 비디오를 읽어오고 실시간으로 처리하여 출력해 보았습니다. OpenCV 코드 설명을 확인해보세요.([바로가기](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/Study/ch18_OpenCV(1).ipynb))
* OpenCV를 이용하여 `Histogram`을 그려보았습니다. 그런데, 히스토그램이란 무엇일까요?
    * [히스토그램이란?](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/F-18%20CV-Histogram.ipynb)
    * 히스토그램을 직접(!!) 구현해보면 그 구조를 좀 더 명확히 이해할 수 있습니다. [라이브러리 없이 히스토그램을 계산하는 코드를 확인해 볼까요?](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/F-18%20CV-Histogram.c)
    
### 10/20 화요일
[F-13], [F-14] Kaggle 시작하기([바로가기](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/Kaggle.ipynb))
* EDA와 데이터 전처리를 진행해 보았습니다. 그러나 해당 노드의 데이터만 가지고는 손에 익숙해지지가 않죠! 직접 캐글에서 여러 데이터를 분석하고 전처리하여 모델에 학습시켜 봅시다. 그 전에, 캐글이 무엇인지, 어떻게 쓰는지 알아볼까요??
    * 데이터 사이언스 competition 플랫폼 : `Kaggle`이란?
    * Kaggle 대회 참가하기

### 10/17 토요일
[F-14], [F-13], [E-2], [F-9] Machine Learning Process ([바로가기](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/Recap-ML.ipynb))
* [F-9]에서 머신러닝 라이브러리 `sklearn`, [F-12]에서 데이터를 시각화하기 위한 `matplotlib`과 `seaborn` 라이브러리를 배운 후, [E-2]에서 아이리스 데이터를 이용한 머신러닝 과정을 실습하였습니다. 이후 [F-13]에서 캐글 포켓몬 데이터를 이용한 EDA, [F-14]에서 `Normalization`, `One-hot Encoding` 등 데이터 전처리 방법을 구체적으로 살펴보았습니다. 머신러닝에 대해 어렴풋이 감이 오시나요?? 순서대로 복습해봅시다.
    * `sklearn` Toy dataset인 wine data를 가지고 sklearn의 데이터 표현법을 살펴봅시다.
    * dataFrame 형태인 iris 데이터를 가지고 classification을 진행해봅시다. **진행 순서**를 잘 기억해주세요.
    * sklearn을 통해 다양한 모델을 사용할 수 있습니다. iris 데이터에는 어떤 모델이 가장 성능이 좋을까요?
    * 라이브러리에서 제공되는 toy dataset은 잘 정제된 데이터셋입니다. 조금 더 날것의 데이터를 가지고 전처리를 진행해 봅시다.(코드 추가 예정입니다!)
    
### 10/16 금요일
[F-13] EDA with Pokemon data([바로가기](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/F-13%20EDA.ipynb))
* 노드의 진행 과정에 따라 등장하는 여러 `Pandas` 메소드들을 정리하고 분석해 보았습니다.
    * `reset_index()`, `isna()`, `isnull()`, `unique()` 등
    * 설명을 따로 드리진 않았지만 `iloc`과 `head()`, `tail()`이라는 메소드가 등장합니다.
    * `iloc`과 `loc`은 어떤 차이점이 있을까요?
* 정규표현식, pandas 조건문 사용하기, pandas Series와 dataframe을 살펴보았습니다.

[F-13] 노드는 굉장히 길고 코드가 많습니다. 실습 코드를 한 번씩 정리해보세요! [이런식으로요!](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/Study/ch13_EDA(Exploratory_Data_Analysis).ipynb)

### 실습자료
* [F-6] Numpy 실습
* [F-9] Sklearn으로 연습하는 Machine Learning Pipeline
* [E-2] Confusion matrix 연습
* [F-13] 포켓몬 데이터로 연습하는 EDA와 Pandas 메소드
* [F-18] OpenCV로 웹캠 읽어오기, 히스토그램 그리기
* [F-28] VGG, ResNet 구현하기

### 복습자료
* [F-3] 파이썬 문법 정리
* [F-3] 파이썬 문법 활용 -> 깜퀴 함께풀기
* [E-2] 머신러닝 프로세스 복습

