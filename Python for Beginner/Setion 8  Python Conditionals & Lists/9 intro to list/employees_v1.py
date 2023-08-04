# employees and their ids
juniors = ['1111', '1113', '1115', '1117','1119', '1121'] # 3
mid_level = ['1311', '1313', '1315', '1317','1319', '1321', '1323', '1325'] #6
seniors = ['1519', '1521', '1523', '1525'] # 9

def main():
    # get id
    id = input("Enter Employee Id: ")

    #  check id
    if not (id in juniors or id in mid_level or id in seniors):
        print(f"{id} Is Not A Employee")
        exit(1)

    # get hourly rate and hours_worked_per_month
    hourly_rate = get_number("Hourly rate")
    hours_worked_per_month = get_number("Hours Worked This Month")

    # calculate salary
    salary = hourly_rate * hours_worked_per_month

    # calculate Bonus 
    if id in juniors:
        total_salary = salary * 3
    elif id in mid_level:
        total_salary = salary * 6
    elif id in seniors:
        total_salary = salary * 9

    print("=" * 40)
    print(f"Employee Id: {id} Gets A Bonus Of {total_salary} EGP.")




def get_number(string):
    while True:
        try:
            num = int(input(f"Enter {string}: "))
            if num < 0:
                print(f"Error {string} should be bigger than zero.")
            else:
                break
        except ValueError:
            print("Invalid Input You Should Enter A NUmeric Value.")
    return num


main()