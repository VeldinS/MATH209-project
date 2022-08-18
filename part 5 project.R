part5 <- read.table("C:/Users/Veldin/CLionProjects/DiscreteMath/cmake-build-debug/part5", quote="\"", comment.char="")

Number_of_crimes_Frequency <- part5$V2

hist(Number_of_crimes_Frequency, main="Histogram for number of crimes people are involved in", xlab="Crimes", ylab = "Number of people", xlim=c(0,900),las=1, 
     breaks=5)

Number_of_crimes_person_is_involved_in_Relative_Frequency <- round(100*part5$V2/sum(part5$V2), 2)

hist(Number_of_crimes_person_is_involved_in_Relative_Frequency, main="Histogram for number of crimes people are involved in", xlab="Crimes", ylab = "Number of people", xlim=c(0,100),las=1, 
     breaks=5)
