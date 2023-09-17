import csv
import pandas as pd
import pyautogui
import time
import os

# --- Step 1: Read text file and Create CSV ---
txt_filename = './data.txt'
csv_filename = './output.csv'

# Read text file
data = []
with open(txt_filename, 'r') as file:
    lines = file.readlines()
    for line in lines[1:]:
        row = line.strip().split(',')
        data.append(row)

# Create CSV file
with open(csv_filename, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(["No", "Customer Name", "Customer Id", "Food Id", "Food Name", "Food Review"])
    csv_writer.writerows(data)

# --- Step 2: Data Analysis ---
df = pd.read_csv(csv_filename)

# Simple Analysis: Count of each food item
food_count = df['Food Name'].value_counts()

# Additional Analyses
summary_stats = df['No'].describe()
unique_customers = df['Customer Id'].nunique()
common_words = pd.Series(' '.join(df['Food Review'].astype(str)).lower().split()).value_counts()[:10]
food_per_customer = df.groupby('Customer Name')['Food Name'].count()

# Combine all analyses into one string
analysis_str = f"""--- Food Count ---
{food_count}

--- Additional Analysis ---
Summary Stats for 'No':
{summary_stats}

Unique Customers: {unique_customers}

Common Words in Food Reviews: {common_words}

Food Items per Customer:
{food_per_customer}
"""

time.sleep(2)
# --- Step 3: Open TextEdit and Pasting Analysis ---
os.system("open /Applications/Microsoft\ Word.app")
time.sleep(3)
pyautogui.hotkey('command', 'o')  
time.sleep(2)
pyautogui.press('enter')
time.sleep(1)

# Paste the analysis
pyautogui.write(analysis_str)
time.sleep(2)

# --- Step 4: Save TextEdit File ---
pyautogui.hotkey('command', 's')  # Save the file
time.sleep(2)
pyautogui.write('./analysis_report')
pyautogui.press('enter')
time.sleep(2)

# Close TextEdit
pyautogui.hotkey('command', 'q')
