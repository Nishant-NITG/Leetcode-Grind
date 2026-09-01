SELECT 
    daily.visited_on,
    SUM(weekly.amount) AS amount,
    ROUND(SUM(weekly.amount) / 7, 2) AS average_amount
FROM (
    SELECT 
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) daily
JOIN (
    SELECT 
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) weekly
ON weekly.visited_on BETWEEN DATE_SUB(daily.visited_on, INTERVAL 6 DAY) 
                         AND daily.visited_on
GROUP BY daily.visited_on
HAVING COUNT(DISTINCT weekly.visited_on) = 7
ORDER BY daily.visited_on;