SELECT P.firstName, P.lastName, A.city, A.state
FROM Person as P
LEFT JOIN Address as A ON P.personID = A.personID