# AIFFEL Basic 여다솔방 자료
[모두의연구소 X sba 아카데미] 아이펠 기본과정 여다솔방 실습자료 및 추가자료, 개인 정리 노트

## 오늘의 자료
### 10/17 토요일
[F-14] Data Preprocessing([바로가기](https://github.com/seraaaayeo/Modulabs-Dasol/blob/master/Recap-ML.ipynb))
* [F-9]에서 머신러닝 라이브러리 `sklearn`, [F-12]에서 데이터를 시각화하기 위한 `matplotlib`과 `seaborn` 라이브러리를 배운 후, [E-2]에서 아이리스 데이터를 이용한 머신러닝 과정을 실습하였습니다. 이후 [F-13]에서 캐글 포켓몬 데이터를 이용한 EDA, [F-14]에서 `Normalization`, `One-hot Encoding` 등 데이터 전처리 방법을 구체적으로 살펴보았습니다. 머신러닝에 대해 어렴풋이 감이 오시나요?? 순서대로 복습해봅시다.
    * `sklearn` Toy dataset인 wine data를 가지고 sklearn의 데이터 표현법을 살펴봅시다.
    * dataFrame 형태인 iris 데이터를 가지고 classification을 진행해봅시다. **진행 순서**를 잘 기억해주세요.
    * sklearn을 통해 다양한 모델을 사용할 수 있습니다. iris 데이터에는 어떤 모델이 가장 성능이 좋을까요?
    * 라이브러리에서 제공되는 toy dataset은 잘 정제된 데이터셋입니다. 조금 더 날것의 데이터를 가지고 전처리를 진행해 봅시다.(코드 추가 예정입니다!)

## 지난 자료들
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

### 복습자료
* [F-3] 파이썬 문법 정리
* [F-3] 파이썬 문법 활용 -> 깜퀴 함께풀기

## 개인 정리자료
* ch12_Visualization(1) : Matplotlib을 이용한 기본 그래프 그리는 법 정리
* ch13_EDA : Kaggle의 Pokemon 데이터를 이용한 EDA 과정 정리
* ch14_Data_preprocessing