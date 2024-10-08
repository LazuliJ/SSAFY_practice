-- 프로그래머스 SELECT문 연습 3번

--정답:
SELECT half.FLAVOR FROM FIRST_HALF as half JOIN ICECREAM_INFO as info ON half.FLAVOR = info.FLAVOR WHERE TOTAL_ORDER > 3000 AND INGREDIENT_TYPE='fruit_based';

--2개 이상의 테이블을 다루기 위해서는 join을 사용해야 한다. (내부조인이라고 함, 만약 FROM에 2개를 나열하면 레코드 해석이 불가능)
--join 하기 위해서는 공통된 요소를 기준으로 한다. (공통된 요소가 아닌 것도 포함하려면 외부 조인을 이용)

--SELECT * FROM table1 JOIN table2 ON table1.value=table2.value;
--이때 공통된 요소는 어떤 테이블에서 가져올 것인지 명확하게 작성해야 한다.
