SELECT AUTHOR_ID, AUTHOR_NAME, CATEGORY, sum(SALES * PRICE) as TOTAL_SALES FROM
    (SELECT BOOK_ID, CATEGORY, a.AUTHOR_ID, PRICE, PUBLISHED_DATE, AUTHOR_NAME FROM BOOK AS b 
     JOIN AUTHOR AS a ON a.AUTHOR_ID=b.AUTHOR_ID) fun_tbl
    JOIN BOOK_SALES AS s ON fun_tbl.book_id=s.book_id
    WHERE YEAR(s.SALES_DATE)='2022' AND MONTH(s.SALES_DATE)='1'
    GROUP BY fun_tbl.author_id, fun_tbl.category
    ORDER BY fun_tbl.author_id, fun_tbl.category DESC;

--JOIN 2번을 할 수 있다.
--살짝 귀찮긴 하지만, 겹치는 줄이 없게 하려면 SELECT 다음에 어떤 값을 불러올지 명시적으로 말한다.
