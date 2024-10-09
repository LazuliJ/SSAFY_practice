-- 프로그래머스 SUM, MAX, MIN문 연습 2번

--정답:
SELECT * FROM FOOD_PRODUCT 
WHERE PRICE=(SELECT MAX(PRICE) FROM FOOD_PRODUCT);

--SELECT를 2번 사용한다.
--sql에서는 어떤 값을 가져오기 위해서는 SELECT를 사용하기 때문이다.
