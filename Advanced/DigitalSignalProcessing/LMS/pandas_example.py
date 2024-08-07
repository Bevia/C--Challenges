import pandas as pd
import matplotlib.pyplot as plt

# Creating a DataFrame
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [24, 27, 22, 32],
    'City': ['New York', 'Los Angeles', 'Chicago', 'Houston']
}
df = pd.DataFrame(data)

# Display the DataFrame
print("DataFrame:")
print(df)

# Selecting a column
print("\nSelecting the 'Name' column:")
print(df['Name'])

# Filtering rows based on a condition
print("\nRows where Age is greater than 25:")
print(df[df['Age'] > 25])

# Adding a new column
df['Salary'] = [50000, 60000, 45000, 70000]
print("\nDataFrame after adding a new column 'Salary':")
print(df)

# Reading from and writing to a CSV file
df.to_csv('people.csv', index=False)
df_from_csv = pd.read_csv('people.csv')
print("\nDataFrame read from 'people.csv':")
print(df_from_csv)

# Plotting the results
plt.figure(figsize=(10, 6))

# Bar plot for Age
plt.subplot(2, 1, 1)
plt.bar(df['Name'], df['Age'], color='skyblue')
plt.title('Age of Individuals')
plt.xlabel('Name')
plt.ylabel('Age')

# Bar plot for Salary
plt.subplot(2, 1, 2)
plt.bar(df['Name'], df['Salary'], color='lightgreen')
plt.title('Salary of Individuals')
plt.xlabel('Name')
plt.ylabel('Salary')

plt.tight_layout()
plt.show()
