SELECT FACTORY_ID, FACTORY_NAME, ADDRESS FROM FOOD_FACTORY
WHERE ADDRESS LIKE '강원도%'
ORDER BY FACTORY_ID;

--특정 단어를 포함하는 요소 검색: LIKE '%글자%'(시작의 경우는 뒤의 % 반대의 경우는 앞의 %만을 붙이기)
