SELECT c.name
FROM Candidate AS c
LEFT JOIN Vote AS v ON c.id = v.candidateId
GROUP BY c.id
ORDER BY COUNT(*) DESC
LIMIT 1