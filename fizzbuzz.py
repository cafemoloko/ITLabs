def fizzbuzz():

    for f in range(101):
        if f % 3 == 0 and f % 5 == 0:
            print("fizzbuzz")           
        if f % 3 == 0:
            print("fizz")   
        if f % 5 == 0:
            print("buzz")
        print(f)


if __name__ == "__main__":
    fizzbuzz()
