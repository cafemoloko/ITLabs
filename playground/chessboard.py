# draw a chess board, parameters: board size and color 

import turtle


screen = turtle.Screen()
pen = turtle.Turtle()

# draws a square 50x50 units
def draw_square():
    for _ in range(4):
        pen.speed(100)
        pen.forward(50)
        pen.left(90)
    pen.forward(50)


if __name__ == "__main__":
    screen.setup(width=0.75, height=0.75) # sets window to 75% of the screen
    screen.title("Turtle Chessboard")

    # numinput returns float, so size has to be converted to int, as its value is used in loops
    size = int(screen.numinput("Chessboard size", "Type the size of the chessboard: ", 8, minval=2, maxval=20))
    color = screen.textinput("Chessboard color", "Choose color: ")

    for i in range(size): 
        pen.up()
        pen.setpos(0, 50 * i)
        pen.down()

        for j in range(size): 
            pen.color(color)

            # counts which squares should be filled with color (even = color, odd = white)
            if (i + j) % 2 == 0:  
                col = color
            else:
                col = "white"

            pen.fillcolor(col)
            pen.begin_fill()
            draw_square()
            pen.end_fill()
        
    screen.exitonclick() # turtle window closes when clicked


