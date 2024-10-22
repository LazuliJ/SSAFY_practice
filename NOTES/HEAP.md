# HEAP

## 개념
- 가장 위의 원소로 항상 최대/최소가 되는 값을 지님
- 이진 트리 자료구조를 지니고 있다.
  
![image](https://github.com/user-attachments/assets/deef7b8e-30f4-4508-900a-e212bd9630ef)
  
- 부모=i라면 자식은 각각 2*i+1, 2*i+2의 번호를 지니고 있다.
- 자식=i라면 부모는 (i-1)/2의 번호를 지니고 있다.

## 추가
- 힙의 가장 끝에 추가한다.
- 그 후, 자신의 부모와 비교해서 크거나/작으면 바꾼다.

## 삭제
- 가장 위의 원소를 삭제한다.
- 가장 끝의 원소를 위에 놓는다
- 자식과 비교하면서 작거나/크면 바꾼다.

## 예시 및 문제
- HEAP의 응용 자료구조로는 Priority Queue가 있다.
- 예시 문제: https://school.programmers.co.kr/learn/courses/30/lessons/42628
