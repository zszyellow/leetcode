SELECT w1.Id FROM Weather w1, Weather w2 
WHERE w1.Temperature > w2.Temperature AND TO_DAYS(w1.DATE)-TO_DAYS(w2.DATE)=1 
