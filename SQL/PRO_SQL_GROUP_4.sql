SELECT CATEGORY, PRICE AS MAX_PRICE, PRODUCT_NAME FROM FOOD_PRODUCT
WHERE (CATEGORY, PRICE) IN (
    -- 서브 쿼리 (카테고리 별 가장 비싼 가격)
    SELECT CATEGORY, MAX(PRICE) FROM FOOD_PRODUCT
    WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
    GROUP BY CATEGORY
)
ORDER BY PRICE DESC;