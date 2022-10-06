from tkinter import *
from tkinter import messagebox
from random import choice, randint, shuffle
import pyperclip
import json


# ---------------------------- PASSWORD GENERATOR ------------------------------- #

def generate_password():
    letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
               'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
               'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

    password_letters = [choice(letters) for _ in range(randint(8, 10))]
    password_symbols = [choice(symbols) for _ in range(randint(2, 4))]
    password_numbers = [choice(numbers) for _ in range(randint(2, 4))]

    password_list = password_letters + password_symbols + password_numbers
    shuffle(password_list)

    password = "".join(password_list)
    password_entry.insert(0, password)
    pyperclip.copy(password)


# ---------------------------- SEARCH WEBSITES ------------------------------- #
def find():
    web = web_entry.get()
    try:
        with open("passwords.json", "r") as pass_file:
            data = json.load(pass_file)
    except FileNotFoundError:
        messagebox.showinfo(title="Error", message="No such file exist")

    else:
        if web in data:
            email1 = data[web]["Email"]
            password1 = data[web]["Password"]
            messagebox.showinfo(title=web, message=f"Email:{email1}\nPassword:{password1}")
        else:
            messagebox.showinfo(title="Error", message=f"There is no data available for {web} please add required data")


# ---------------------------- SAVE PASSWORD ------------------------------- #
def save():
    web = web_entry.get()
    em = email_entry.get()
    pa = password_entry.get()
    new_data = {
        web: {
            "Email": em,
            "Password": pa,
        }
    }
    if len(web) == 0 or len(pa) == 0:
        messagebox.showinfo(title="Empty Field", message="Please enter valid entries.")
    else:
        try:
            with open("passwords.json", "r") as pass_file:
                data = json.load(pass_file)
        except FileNotFoundError:
            with open("passwords.json", "w") as pass_file:
                json.dump(new_data, pass_file, indent=4)
        else:
            data.update(new_data)
            with open("passwords.json", "w") as pass_file:
                json.dump(data, pass_file, indent=4)
        finally:
            web_entry.delete(0, END)
            password_entry.delete(0, END)


# ---------------------------- UI SETUP ------------------------------- #

window = Tk()
window.title("Password manager")
window.config(padx=50, pady=50)

canvas = Canvas(height=200, width=200);
logo = PhotoImage(file="logo.png")
canvas.create_image(100, 100, image=logo)
canvas.grid(row=0, column=1)

# Labels
website = Label(text="Website:")
website.grid(row=1, column=0)
email = Label(text="Email:")
email.grid(row=2, column=0)
password = Label(text="Password:")
password.grid(row=3, column=0)

# Entries
web_entry = Entry(width=21)
web_entry.grid(row=1, column=1)
web_entry.focus()
email_entry = Entry(width=39)
email_entry.grid(row=2, column=1, columnspan=2)
email_entry.insert(0, "akshayverma887462gmail.com")
password_entry = Entry(width=21)
password_entry.grid(row=3, column=1)

# Buttons
search = Button(text="Search", width=13, command=find)
search.grid(row=1, column=2)
generate = Button(text="Generate Password", command=generate_password)
generate.grid(row=3, column=2)
add = Button(text="Add", width=36, command=save)
add.grid(row=4, column=1, columnspan=2)
window.mainloop()
