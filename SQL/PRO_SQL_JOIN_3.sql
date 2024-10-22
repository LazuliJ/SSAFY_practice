-- 메인쿼리. 상위 FLAVOR 3개 뽑기
SELECT C.FLAVOR FROM
-- 서브쿼리 2. 총합 구하기
(SELECT A.FLAVOR, A.TOTAL_ORDER+B.TOTAL_ORDER AS ORDERS FROM FIRST_HALF AS A 
JOIN (
    -- 서브쿼리1. JULY를 맛별로 통합해서 총 개수 구하기
    SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER FROM JULY
    GROUP BY FLAVOR
) B ON A.FLAVOR=B.FLAVOR
ORDER BY ORDERS DESC) C
-- 개수 제한: LIMIT NUM;
LIMIT 3;