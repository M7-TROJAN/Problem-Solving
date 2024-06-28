import turtle

def draw_rectangle(t, width, height, color):
    """Draw a filled rectangle."""
    t.color(color)
    t.begin_fill()
    for _ in range(2):
        t.forward(width)
        t.right(90)
        t.forward(height)
        t.right(90)
    t.end_fill()

def draw_flag():
    # Set up the screen
    screen = turtle.Screen()
    screen.title("Flag of Palestine")
    screen.bgcolor("white")

    # Create a turtle object
    flag_turtle = turtle.Turtle()
    flag_turtle.speed(5)

    # Define the flag proportions
    flag_height = 400
    flag_width = 650
    stripe_height = flag_height / 3

    # Draw the black, white, and green stripes
    colors = ["black", "white", "green"]
    for i, color in enumerate(colors):
        flag_turtle.penup()
        flag_turtle.goto(-flag_width/2, flag_height/2 - i*stripe_height)
        flag_turtle.pendown()
        draw_rectangle(flag_turtle, flag_width, stripe_height, color)

    # Draw the red triangle
    flag_turtle.penup()
    flag_turtle.goto(-flag_width/2, flag_height/2)
    flag_turtle.pendown()
    flag_turtle.color("red")
    flag_turtle.begin_fill()
    flag_turtle.goto(0, 0)
    flag_turtle.goto(-flag_width/2, -flag_height/2)
    flag_turtle.goto(-flag_width/2, flag_height/2)
    flag_turtle.end_fill()

    # Hide the turtle and display the flag
    flag_turtle.hideturtle()
    turtle.done()

# Call the function to draw the flag
draw_flag()
