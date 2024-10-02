DELETE p1 FROM PERSON AS p1, PERSON AS p2
WHERE p1.email = p2.email AND p1.id > p2.id