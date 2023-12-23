# Course: EHB420E ARTIFICIAL NEURAL NETWORKS
# Instructor:Dr. Öğr. Üyesi Onur Ergen
# Student: Javad Ibrahimli
# Student ID: 040210932
# Date: 24.11.2023
# Description: This program calculates the total electric bill of a user by taking the user's first name, last name, electric amount used and discount contract status as inputs. The program uses tkinter library to create a GUI and display the result in a messagebox.
# Code editor: Visual Studio Code 1.61.2
# Python version: 3.9.7

#required libraries in order to create program
import tkinter as tk
from tkinter import messagebox

# I set a class for the Electric Bill Calculator
class ElectricBillCalculator:
    def __init__(self, root):
        self.root = root # Create a root window
        self.root.title("Electric Bill Calculator - Sena Keleser")  # Set the title of the root window

        self.first_name_variable = tk.StringVar() # Create a variable for the first name
        self.lastname_variable = tk.StringVar()  # Create a variable for the last name
        self.amount_variable = tk.StringVar() # Create a variable for the electric amount
        self.discount_contract = tk.StringVar() # Create a variable for the discount contract
        self.discount_contract.set("no")  # Set the default value of the discount contract variable to "no"

        # Create and place widgets
        self.widget_creator()

# I set a function for the widgets in the class 
    def widget_creator(self):
        # Labels and Entry widgets
        tk.Label(self.root, text="First Name:").grid(row=0, column=0, padx=10, pady=5) # Create a label widget 
        tk.Entry(self.root, textvariable=self.first_name_variable).grid(row=0, column=1, padx=10, pady=5) # Create an entry widget 

        tk.Label(self.root, text="Last Name:").grid(row=1, column=0, padx=10, pady=5) # Create a label widget 
        tk.Entry(self.root, textvariable=self.lastname_variable).grid(row=1, column=1, padx=10, pady=5) # Create an entry widget

        tk.Label(self.root, text="Electric Usage (kWh):").grid(row=2, column=0, padx=10, pady=5) # Create a label widget 
        tk.Entry(self.root, textvariable=self.amount_variable).grid(row=2, column=1, padx=10, pady=5) # Create an entry widget 

        tk.Label(self.root, text="Discount Contract:").grid(row=3, column=0, padx=10, pady=5) # Create a label widget
        tk.Radiobutton(self.root, text="Yes", variable=self.discount_contract, value="yes").grid(row=3, column=1, padx=10, pady=5)
        tk.Radiobutton(self.root, text="No", variable=self.discount_contract, value="no").grid(row=3, column=2, padx=10, pady=5)

        # Calculate button
        tk.Button(self.root, text="Calculate", command=self.calculate_bill).grid(row=4, column=0, columnspan=3, pady=10) # Create a button widget

    def calculate_bill(self): # Calculate bill function
        # Get user inputs
        first_name = self.first_name_variable.get() # Get the value of the first name variable
        last_name = self.lastname_variable.get() # Get the value of the last name variable
        electric_amount_used = self.amount_variable.get()   # Get the value of the electric amount variable
        discount_status = self.discount_contract.get() # Get the value of the discount contract variable

        try: # Try to convert the input string to float
            electric_amount = float(electric_amount_used) # change the input string to float in order to calculate

            # Calculate the total electric bill
            total_electric_bill = self.calculate_total_electric_bill(electric_amount, discount_status)

            # Display the result in a messagebox with two decimal places
            result_info = f"Dear {first_name} {last_name},\nYour total electric bill is: {total_electric_bill:.2f} Turkish Lira"
            messagebox.showinfo("Result", result_info)

        except ValueError: # If the input string cannot be converted to float display an error message
            messagebox.showerror("Error", "Your input for electric amount is not valid. Please enter a valid numeric value for electric amount.")

    def calculate_total_electric_bill(self, electric_amount, discount_contract): # Calculate the total electric bill function with parameters
        # Constants
        AU = 0.91555  # Active Energy Unit Price
        VAT = 0.18    # Value Added Tax
        DISTRIBUTION_FEE_UNIT = 0.2651   # Distribution Fee Unit Price
        FUND_FEE_RATE = 0.007  # Energy Fund Fee Rate

        # Calculate active energy price (Active Energy Unit Price * electric amount)
        standart_energy_price = AU * electric_amount

        # Calculate distribution fee
        distribution_fee_amount = 0 if discount_contract == "yes" else DISTRIBUTION_FEE_UNIT * electric_amount 

        # Calculate energy fund fee (F = 0.7% * (Active Energy Unit Price * electric amount)
        fund_fee = standart_energy_price * FUND_FEE_RATE

        # Calculate total before VAT (Active Energy Price + Distribution Fee + Energy Fund Fee)
        total_amount_before_VAT = standart_energy_price + distribution_fee_amount + fund_fee

        # Calculate total electric bill
        total_bill = (1 + VAT) * total_amount_before_VAT 

        return total_bill # Return is used to return a value from a function

# Create the main window with tkinter
program1 = tk.Tk() 

# Create an instance of the ElectricBillCalculator class and pass the root window as a parameter
app = ElectricBillCalculator(program1)

# Start the mainloop of the root window
program1.mainloop()
