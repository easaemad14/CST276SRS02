# CST276SRS02  

Date Validation Strategy/Template Method  

Name: Easa El Sirgany 

---
Issues:  
	None

Notes:  
	My implementation strayed from the SRS a bit.

	I didn't like the interface requirement, because my first implementation implemented
	several small methods for checking the various components of the date string, so the
	DateValidator (which is still an abstract base class to match the GoF Strategy
	Pattern) doesn't comprise solely of pure virtual functions.

	Also, the point of the project may have been lost on me. I believe the objective was
	to implement the enumerated version and notice a similarity, where I would just make
	small improvements to my DateValidator, but for me there was a lot of rewriting of
	the validator.

	For the enumerated version, all I changed was the switch statement in my date
	validator's functor and added the enumeration value (as well as the extra check
	in my main tester). The con of this type of change is obvious: if you forget to
	update your enum class, you'll use the default of your switch statement which you
	may not even realize before it's too late. The pro would be less code changes, which
	would make it easier to understand if you are looking at the changes specifically.
	
	This was similar in my Strategy Pattern implementation, where I created a new derived
	class (so I guess it was a little simpler, maybe). The con of this is more code had
	to be changed (depending on the size of the class that you are implementing), and the
	pro would be that you could never get into a situation where you use a different
	derived algorithm.

###

