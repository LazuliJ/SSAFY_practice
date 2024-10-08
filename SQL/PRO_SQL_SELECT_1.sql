-- 프로그래머스 SELECT문 연습 1번

--정답:
SELECT ROUND(AVG(DAILY_FEE), 0) as AVERAGE_FEE FROM CAR_RENTAL_COMPANY_CAR WHERE CAR_TYPE='SUV';

--SELECT문의 기본 형태: SELECT * FROM table;
--평균구하기: AVG(value);
--반올림: ROUND(value, 자릿수);
---> 이때 소수점 첫째자리에서 반올림하라고 하면 자릿수에 0을 넣어야 함.
--조건문 검색: LIKE든 BETWEEN이든 조건문이 들어간다면 WHERE가 들어가야 함.
