const questions = [
   {
   	   question:"What is the capital of Germany?",
   	   answers: [
   	        { text:"a) Berlin", correct:true},
   	        { text:"b) Dublin", correct:false},
   	        { text:"c) Budapest", correct:false},
   	        { text:"d) Kiwi", correct:false},
   	   	]
   },
   {
   	    question:"What is the capital of Tanzania?",
   	    answers: [
   	        { text:"a) Mogadishu", correct:false},
   	        { text:"b) Moscow", correct:false},
   	        { text:"c) Dodoma", correct:true},
   	        { text:"d) Khartoum", correct:false},
   	   	]
   },
    {
   	    question:"What is the capital of Nigeria?",
   	    answers: [
   	        { text:"a) Pretoria", correct:false},
   	        { text:"b) Abuja", correct:true},
   	        { text:"c) Addis Ababa", correct:false},
   	        { text:"d) Rabat", correct:false},
   	   	]
   },
    {
   	    question:"What is the capital of Argentina?",
   	    answers: [
   	    	{ text:"a) Madrid", correct:false},
   	        { text:"b) Buenos Aires", correct:true},
   	        { text:"c) Cranberra", correct:false},
   	        { text:"d) Barcelona", correct:false},
   	   	]
   },
    {
   	    question:"What is the capital of Mali?",
   	    answers: [
   	        { text:"a) Banjul", correct:false},
   	        { text:"b) Accra", correct:false},
   	        { text:"c) Bamaku", correct:true},
   	        { text:"d) Cairo", correct:false},
   	   	]
   },
    {
   	    question:"What is the capital of Senegal?",
   	    answers: [
   	        { text:"a) Dakar", correct:false},
   	        { text:"b) Beijing", correct:false},
   	        { text:"c) Kampala", correct:true},
   	        { text:"d) Libreville", correct:false},
   	   	]
   },
    {
   	    question:"What is the capital of Kenya?",
   	    answers: [
   	        { text:"a) Nairobi", correct:true},
   	        { text:"b) Maputo", correct:false},
   	        { text:"c) Lukasa", correct:false},
   	        { text:"d) Maseru", correct:false},
   	   	]
   },
    {
   	    question:"What is the capital of USA?",
   	    answers: [
   	        { text:"a) Toronto", correct:false},
   	        { text:"b) New York", correct:false},
   	        { text:"c) Washington DC", correct:true},
   	        { text:"d) Calgary", correct:false},
   	   	]
   },
    {
   	    question:"What is the capital of Bolivia?",
   	    answers: [
   	        { text:"a) Astana", correct:false},
   	        { text:"b) Yerevan", correct:false},
   	        { text:"c) Sofia", correct:false},
   	        { text:"d) La Paz", correct:true},
   	   	]
   },
    {
   	    question:"What is the capital of Bahrain?",
   	    answers: [
   	        { text:"a) Manama", correct:true},
   	        { text:"b) Abu Dhabi", correct:false},
   	        { text:"c) Wellington", correct:false},
   	        { text:"d) Riyadh", correct:false},
   	   	]
   }

]
        
        const questionElement = document.getElementById("ques");
        const answerElement = document.getElementById("main");
        const nextElement = document.getElementById("Next");
        const timer_text = document.getElementById("times");
        const timer_seconds = document.getElementById("ticks");
        const questionCounter = document.getElementById("counter");
        const start_btn = document.getElementById("btn"); 
        const quizbox = document.getElementById("quiz1");
        const displaymsg = document.getElementById("startscreen");


        let currentQuesIndex = 0;
        let score = 0;

        start_btn.onclick = ()=>{
    
            quizbox.style.display = "block";
            displaymsg.style.display = "none";
            displaymsg.style.pointerEvents = "none";
            quizbox.style.pointerEvents = "auto";
            document.body.style.backgroundImage = 'url(../quiz/blackback.jpg)';
            quizbox.style.backgroundImage = 'url(../quiz/back.png)';
            startQuiz();
        }
         

        function startQuiz() {
            currentQuesIndex = 0;
            score = 0;
            questionCounter.innerHTML = 1;
            nextElement.innerHTML = "Next";
            showQuestion();
            startTimer(15);
        }
        
        let timeValue = 15;

        function showQuestion() {
            resetState();
            let currentQuestion = questions[currentQuesIndex];
            let questionNo = currentQuesIndex + 1;
            questionElement.innerHTML = questionNo + "- " + currentQuestion.question;

            currentQuestion.answers.forEach(answer => {
                const option = document.createElement("div");
                option.innerHTML = answer.text;
                option.classList.add("option");
                answerElement.appendChild(option);
                if (answer.correct) {
                    option.dataset.correct = answer.correct;
                    
                }
                option.addEventListener("click", selectAnswer);
            });
        }

        function resetState() {
            nextElement.style.display = "none";
            while (answerElement.firstChild) {
                answerElement.removeChild(answerElement.firstChild);
            }
        }

        function selectAnswer(e) {
            clearInterval(counter);
            const selectedAns = e.target;
            const isCorrect = selectedAns.dataset.correct === "true";
            if (isCorrect) {
                selectedAns.classList.add("correct");

                score++;
            } else {
                selectedAns.classList.add("incorrect");
                
            }
            Array.from(answerElement.children).forEach(option => {
                if (option.dataset.correct === "true") {
                    option.classList.add("correct");
                }
                option.classList.add("disable");
                
            });
            nextElement.style.display = "block";
        }

        function showScore() {
            resetState();
            answerElement.classList.add("showresult");
            questionElement.innerHTML = `You scored ${score} out of ${questions.length}!`;
            nextElement.classList.add("playagainbtn");
            nextElement.innerHTML = "Play Again";
            nextElement.style.display = "block";
            quizbox.style.backgroundImage = 'url(../quiz/pic3.png)';
        }

        function handleNextOption() {
            currentQuesIndex++;
            if (currentQuesIndex < questions.length) {
                showQuestion();
                timer_seconds.innerHTML = 15;
                questionCounter.innerHTML++;
                clearInterval(counter);
                startTimer(15);

            } else {
                showScore();
            }
        }

        nextElement.addEventListener("click", () => {
            if (currentQuesIndex < questions.length) {
                handleNextOption();
            } else {
                quizbox.style.display = "none";
                displaymsg.style.display = "block";
                displaymsg.style.pointerEvents = "auto";
                quizbox.style.pointerEvents = "none";
                document.body.style.backgroundImage = 'url(../quiz/pic3.jpg)';

            }
        });

        let counter = 0;

        function startTimer(time) {
            counter = setInterval(timer, 1000);
            function timer() {
                timer_seconds.textContent = time;
                time--;

                if(time < 9) {
                    let addZero = timer_seconds.textContent;
                    timer_seconds.textContent = "0" + addZero;
                }

                if (time < 0) {
                    clearInterval(counter);
                     //getting all option items
                    // let correcAns = questions[currentQuesIndex].answers.text; //getting correct answer from array
                    // for(i=0; i < 4; i++) {
                    //     if(option.textContent == correcAns){ //if there is an option which is matched to an array answer
                    //         option.setAttribute("class", "option correct"); //adding green color to matched option
                    //         option.insertAdjacentHTML("beforeend", tickIconTag); //adding tick icon to matched option
                    //         console.log("Time Off: Auto selected correct answer.");
                    //     }
                    // }
                    // for(i=0; i < 4; i++) {
                    //     option.classList.add("disabled"); //once user select an option then disabled all options
                    // }
                    
                    nextElement.classList.add("show"); //show the next button if user selected any option
                }

            }
        }

       