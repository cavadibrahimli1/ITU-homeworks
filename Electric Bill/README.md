![image](https://github.com/cavadibrahimli1/ITU-homeworks./assets/76445357/a514cb08-2e59-4e34-add9-85659000e33e)


# Electric Bill Calculator
## Course Information
- Course: EHB420E ARTIFICIAL NEURAL NETWORKS
- Instructor: Dr. Öğr. Üyesi Onur Ergen
- Student: Javad Ibrahimli
- Student ID: 040210932
- Date: 24.11.2023
- Overview
This program is a simple Electric Bill Calculator that takes user inputs such as first name, last name, electric amount used, and discount contract status. It utilizes the tkinter library to create a Graphical User Interface (GUI) and displays the calculated electric bill in a messagebox.

## Development Environment
- Code Editor: Visual Studio Code 1.61.2
- Python Version: 3.9.7
## Prerequisites
Ensure you have the necessary libraries installed by running the following command:
```bash
    pip install tk

```
## How to Use
- Run the program using the Python interpreter.
- Input the required information in the provided fields.
- Click the "Calculate" button to see the total electric bill in a messagebox.
Code Structure
- The ElectricBillCalculator class is defined to handle GUI creation and event handling.
- Widgets (labels, entry fields, radio buttons, and buttons) are created and placed using the widget_creator method.
- The calculate_bill method processes user inputs, calculates the electric bill, and displays the result in a messagebox.
- The calculate_total_electric_bill method calculates the total electric bill based on predefined constants.
## Constants
- AU: Active Energy Unit Price
- VAT: Value Added Tax
- DISTRIBUTION_FEE_UNIT: Distribution Fee Unit Price
- FUND_FEE_RATE: Energy Fund Fee Rate
## Disclaimer
This program assumes valid input for electric amount and provides an error message for invalid input. Feel free to explore and modify the code as needed. If you encounter any issues or have suggestions for improvement, please let me know.
