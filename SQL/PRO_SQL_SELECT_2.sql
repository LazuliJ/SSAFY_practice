-- 프로그래머스 SELECT문 연습 2번

--정답:
SELECT DR_NAME, DR_ID, MCDP_CD, DATE_FORMAT(HIRE_YMD, '%Y-%m-%d') FROM DOCTOR WHERE MCDP_CD='CS' OR MCDP_CD='GS' ORDER BY HIRE_YMD DESC, DR_NAME ASC;

--SELECT문의 기본 형태: SELECT value FROM table;
--조건문 2개 연결: AND 또는 OR
--값에 따른 정렬: ORDER BY value ASC(미지정시 기본값, DESC);
---> 2개 이상 연결시 우선시 되는 값을 앞에 적는다. SELECT문에서 값 나열하듯 value1 ASC(또는 DESC), value2 ASC(DESC); 쓰면 된다.
--날짜 형식 지정: DATE_FORMAT(value, format)
---> %Y = 연도 %m = 달 (대문자시 글자로) %d = 날 (대문자시 글자로)
