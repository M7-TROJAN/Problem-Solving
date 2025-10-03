// get the elements from the DOM
const welcomeSection = document.getElementById("welcome-section");
const quizSection = document.getElementById("quiz-section");
const resultSection = document.getElementById("result-section");
const questionCountInput = document.getElementById("question-count");
const startBtn = document.getElementById("start-btn");
const questionText = document.getElementById("question-text");
const optionsContainer = document.getElementById("options-container");
const progressBar = document.getElementById("progress-bar");
const timerElement = document.getElementById("timer");
const resultSummary = document.getElementById("result-summary");
const restartBtn = document.getElementById("restart-btn");

// Quiz Data Variables
let questions = []; // Store the questions from JSON
let currentQuestionIndex = 0;
let timer;
let timeLeft = 30;

// Variables for tracking performance
let correctAnswersCount = 0;
let wrongAnswersCount = 0;
const reviewData = []; // Store the review data for each question

// Load Questions from JSON
async function loadQuestions() {
    const response = await fetch("questions.json");
    questions = await response.json();
}

// Start Timer
function startTimer() {
    timeLeft = 30;
    timerElement.textContent = `${timeLeft}s`;
    progressBar.style.width = "100%";
    progressBar.ariaValueNow = 100;

    timer = setInterval(() => {
        timeLeft--;
        timerElement.textContent = `${timeLeft}s`;
        progressBar.style.width = `${(timeLeft / 30) * 100}%`;

        if (timeLeft <= 0) {
            clearInterval(timer);
            showCorrectAnswer();
            setTimeout(nextQuestion, 1000);
        }
    }, 1000);
}

// Display Question
function displayQuestion() {
    const question = questions[currentQuestionIndex];
    const questionBox = document.createElement("div");
    questionBox.className = "question-box";

    // Display the question text
    const questionText = document.createElement("h2");
    questionText.textContent = question.question;
    questionBox.appendChild(questionText);

    // Display the options
    question.options.forEach((option, index) => {
        const button = document.createElement("button");
        button.className = "btn btn-outline-secondary";
        button.textContent = option;
        button.onclick = () => handleAnswer(index + 1);
        questionBox.appendChild(button);
    });

    // Clear the container and append the question
    optionsContainer.innerHTML = "";
    optionsContainer.appendChild(questionBox);

    startTimer();
}

// handleAnswer Function
function handleAnswer(selectedOption) {
    clearInterval(timer);
    const question = questions[currentQuestionIndex];
    const buttons = optionsContainer.querySelectorAll("button");

    if (selectedOption === question.correctOption) {
        correctAnswersCount++;
        reviewData.push({ question: question.question, yourAnswer: question.options[selectedOption - 1], isCorrect: true });
        buttons[selectedOption - 1].classList.add("correct-border");
    } else {
        wrongAnswersCount++;
        reviewData.push({
            question: question.question,
            yourAnswer: question.options[selectedOption - 1],
            isCorrect: false,
            correctAnswer: question.options[question.correctOption - 1],
        });
        buttons[selectedOption - 1].classList.add("wrong-border");
        buttons[question.correctOption - 1].classList.add("correct-border");
    }
    setTimeout(nextQuestion, 1000);
}

// Show Correct Answer
function showCorrectAnswer() {
    const question = questions[currentQuestionIndex];
    const buttons = optionsContainer.querySelectorAll("button");
    buttons[question.correctOption - 1].classList.add("correct-border");
}

// Move to Next Question
function nextQuestion() {
    if (currentQuestionIndex + 1 >= questions.length) {
        showPerformance();
    } else {
        currentQuestionIndex++;
        displayQuestion();
    }
}

// Show Results 
function showPerformance() {
    quizSection.classList.add("d-none");
    const performanceSection = document.getElementById("performance-section");
    performanceSection.classList.remove("d-none");

    document.getElementById("total-questions").textContent = questions.length;
    document.getElementById("correct-answers").textContent = correctAnswersCount;
    document.getElementById("wrong-answers").textContent = wrongAnswersCount;
    document.getElementById("accuracy").textContent = ((correctAnswersCount / questions.length) * 100).toFixed(2);

    const reviewList = document.getElementById("review-list");
    reviewList.innerHTML = "";
    reviewData.forEach((data, index) => {
        const listItem = document.createElement("li");
        listItem.className = "list-group-item";
        listItem.innerHTML = `
            <strong>Q${index + 1}: ${data.question}</strong><br>
            <span class="${data.isCorrect ? "correct-answer" : "wrong-answer"}">
                Your Answer: ${data.yourAnswer}
            </span>
            ${!data.isCorrect ? `<br><span class="correct-answer">Correct Answer: ${data.correctAnswer}</span>` : ""}
        `;
        reviewList.appendChild(listItem);
    });
}

// Start Quiz
startBtn.onclick = async () => {
    const questionCount = parseInt(questionCountInput.value);
    if (questionCount < 1 || questionCount > 100 || isNaN(questionCount)) {
        alert("Please enter a valid number between 1 and 100.");
        return;
    }

    await loadQuestions();
    questions = questions.sort(() => 0.5 - Math.random()).slice(0, questionCount); // Shuffle and select questions

    welcomeSection.classList.add("d-none");
    quizSection.classList.remove("d-none");
    displayQuestion();
};

// Restart Button Event Listener
restartBtn.addEventListener('click', restartQuiz);

// Restart Quiz Function
function restartQuiz() {
    correctAnswersCount = 0;
    wrongAnswersCount = 0;
    reviewData.length = 0;
    currentQuestionIndex = 0;
    document.getElementById("performance-section").classList.add("d-none");
    welcomeSection.classList.remove("d-none");
}