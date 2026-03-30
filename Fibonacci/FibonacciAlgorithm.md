# 과제2 : 피보나치 복잡도 프로파일링 보고서

## 이전 과제 코드
GCD,LCM

#main.c
https://github.com/juyeop00919/dataStructure/blob/main/GCDLCM/main.c

#my_math.c
https://github.com/juyeop00919/dataStructure/blob/main/GCDLCM/my_math.c

#my_math.h
https://github.com/juyeop00919/dataStructure/blob/main/GCDLCM/my_math.h

## 1. 과제 1 (GCD) 시간복잡도 검증

### GCD의 시간복잡도
GCD의 시간복잡도는 **$O(\log n)$** 입니다. (단, n = a,b 중 작은 수) 

### 1번 과제 검증
* GCD의 시간 복잡도 **$O(\log n)$** 의 n은 숫자이나 피보나치 수열의 n은 몇 번째 항인가? 입니다. 그래서 피보나치 함수의 결과 값 $N$ ( $fib(n)$ ) 값이 들어가야 합니다.
* 피보나치 수열의 일반항은 $$\phi = \frac{1 + \sqrt{5}}{2} \approx 1.618$$ 이므로 황금비를 가집니다.
* 피보나치 수열의 인덱스 ($n$) 가 1증가할 때마다, 그 값($N$) 은 약 1.618배씩 커진다고 볼 수 있습니다.
* 이를 수식으로 표현할 시 $N=\phi^n$ 이 됩니다. (  $$n \times \log(\phi)$$ ) 
* 즉 $$\log(\phi)$$ 은 고정된 상수( $\approx 0.2089$ ) 이므로 $$y = ax$$ 형태를 가지게 됩니다.
* 그러므로 연산 횟수는 인덱스 $n$에 비례하여 **선형적( $O(n)$ )** 으로 증가합니다.
<img width="471" height="285" alt="Image" src="https://github.com/user-attachments/assets/25311f90-160d-4be3-9148-3d14602929f2" />

* 피보나치 수열 계산 시간은 포함되지 않았습니다.
* 그래프의 형태를 보면 $O(n)$ 형식의 그래프로 GCD의 시간복잡도는 **$O(\log n)$**  가 옳다고 볼 수 있음.

## 2. 피보나치 수열의 시간복잡도
* 피보나치 수열의 일반항은 $$\phi = \frac{1 + \sqrt{5}}{2} \approx 1.618$$ 이므로 황금비를 가집니다.
* 피보나치 수열의 인덱스 ($n$) 가 1증가할 때마다, 그 값($N$) 은 약 1.618배씩 커진다고 볼 수 있습니다.
* 이를 수식으로 표현할 시 $\log(\phi^n)$ 이 됩니다. (  $$n \times \log(\phi)$$ )
* 시간 복잡도는 $O(2^n)$ 입니다. (정확히는 $O(1.618^n)$ )

<img width="297" height="757" alt="Image" src="https://github.com/user-attachments/assets/cc3dd509-fcea-47de-b7bd-a3df6464d1ba" />
<img width="475" height="284" alt="Image" src="https://github.com/user-attachments/assets/7f583455-7244-4ef6-ac46-05091a798956" />


* 실제 코드를 돌려본 그래프 그러나 $n-1$ + $n-2$ $\approx$ $n$ 의 출력시간을 가지므로 예상한 시간을 가지고 그래프를 만들어볼 수 있음

<img width="471" height="283" alt="Image" src="https://github.com/user-attachments/assets/f0873345-14c3-4090-b65c-3e3ddce54e6d" />


### 프로파일링 이미지
<img width="3037" height="1073" alt="Image" src="https://github.com/user-attachments/assets/85a6532b-08cc-4a31-97fc-d1c82d359733" />
<img width="1790" height="965" alt="Image" src="https://github.com/user-attachments/assets/6c83829a-c4ed-4e38-9a10-79ce0a281813" />

* 또한 이 사진에서 볼 수 있듯 fib 함수 99%의 수치에 비해 get_gcd 함수는 0.9% 라는 작은 연산량을 가짐
* GCD는 연산량이 매우 적어 프로파일링에 안나와서 GCD 연산 100만번 수행했습니다.
  
<img width="1787" height="971" alt="Image" src="https://github.com/user-attachments/assets/541d91d6-dfc5-4507-8ec4-ba09fe77acb3" />


