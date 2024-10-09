-- 프로그래머스 SUM, MAX, MIN문 연습 9번

--정답:
SELECT CONCAT(CAST(MAX(LENGTH) AS CHAR), 'cm') as MAX_LENGTH FROM FISH_INFO;

--숫자를 문자열로 바꾸기: CAST(num AS CHAR)
--문자열끼리 합치기: CONCAT(char1, char2)
