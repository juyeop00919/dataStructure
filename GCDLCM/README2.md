# GCD LCM 최대공약수 최소공배수

### 1. 알고리즘
GCD,을 구하기 위해 유클리드 호제법을 사용했습니다.
두 양의 정수 a,b 에 대해 a=bq  + r (q는 몫, r은 나머지) 라고 할 때, GCD(a,b) = GCD(b,r) 입니다. r이 0이 될 때까지 반복하면 GCD를 구할 수 있습니다. 

LCM은 GCD를 이용하여 LCM(a,b) = (a*b)/GCD로 구할 수 있습니다.

### 2. 함수
- 'get_gcd' : 최대공약수 계산
- 'get_lcm' : 최소공배수 계산


### 3.알고리즘 기술 언어
GCD : 순서도를 활용한 표현
LCM : 자연어를 이용한 서술적 표현

![Image](https://github.com/user-attachments/assets/5d73160b-6cf5-45d5-9c4f-f11279ef68c7)




