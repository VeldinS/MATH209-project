part6 <- read.table("C:/Users/Veldin/CLionProjects/DiscreteMath/cmake-build-debug/part6", quote="\"", comment.char="")

part6$part6_Cat<-cut(part6$V1, 
                     breaks=seq(0.5, 551.5, 1))

Number_of_people_involved_in_crime_Frequency <- table(part6$part6_Cat)
hist(Number_of_people_involved_in_crime_Frequency,main="Histogram for number of people involved in a crime", xlab="Number of people", ylab = "Crimes")



round(100*table(part6$part6_Cat)/sum(table(part6$part6_Cat)), 2)
hist(Number_of_people_involved_in_crime_Frequency,main="Histogram for number of people involved in a crime", xlab="Number of people", ylab = "Crimes")




