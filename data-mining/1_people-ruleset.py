import pandas as pd
import matplotlib.pyplot as plt

def check_age(f):
    # DataFrame.apply calls this lambda function with each row (axis = 1) as argument
    # row[0] is age, row[1] is yearsmarried
    age_conditions = lambda row : row[0] in range(0,151) and row[0] > row[1]
    result = f[['age', 'yearsmarried']].apply(age_conditions, axis = 1) 
    f['passes_ruleset'] &= result
    print(result)

def agegroup_conditions(row):
    age = row[0]
    agegroup = row[1]
    if(age < 18 and agegroup == "child"):
        return True
    elif(age >= 18 and age <= 65 and agegroup == "adult"):
        return True
    elif(age > 65 and agegroup == "elderly"):
        return True

    return False

def check_agegroup(f):
    # apply the function to each row
    result = f[['age', 'agegroup']].apply(agegroup_conditions, axis = 1)
    print(result)
    f['passes_ruleset'] &= result

def check_height(f):
    pass

def check_status(f):
    status_condition = lambda s : s in ["single", "married", "widowed"]
    result = f['status'].apply(status_condition) 
    print(result)
    f['passes_ruleset'] &= result


def check_yearsmarried(f):
    pass

data_file = "people.txt"
f = pd.read_csv(data_file)
print(f"=> Data read from '{data_file}':\n", f, "\n")

# Create a summary column that will keep track of which records have passed / failed ruleset checks.
# Initially, we assume all records pass the resultset. If during checking we find out a record has
# failed a check, then we set it to False.
#
passes_ruleset = [True for i in range(f.shape[0])]
# add this column to the end of data frame f
f['passes_ruleset'] = passes_ruleset

ruleset = {
    'age': check_age,
    'agegroup': check_agegroup,
    'height': check_height,
    'status': check_status,
    'yearsmarried': check_yearsmarried
}

# if we want to check all columns, then we can use f.columns
# for col in f.columns:
for col in ['age', 'agegroup', 'status']:
    print("\n--------------------------")
    print(f"=> Checking column '{col}':")
    ruleset[col](f)
    print("--------------------------")

print("\n\n--------------------------------------------")
print("=> Summary of results:\n", f)
print("--------------------------------------------")

# plot all records
f.plot(title = 'Original set of records')
plt.show()

# plot only the records which pass the ruleset conditions.
rf = f[f['passes_ruleset'] == True]
rf.plot(title = 'Set of records after applying the ruleset')
plt.show()

