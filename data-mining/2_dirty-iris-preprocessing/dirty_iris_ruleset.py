import numpy as np
# ruleset for the dirty iris data set

def check_sepal_length(df):
    result = np.array(df['Sepal.Length'] <= 30)
    
    fail_indices = np.nonzero(result == False)[0]
    print("Records violating this rule: ")
    print(df.iloc[fail_indices])
    
    num_violations = np.size(result) - np.count_nonzero(result)
    return num_violations

def check_sepal_width(df):
    pass

def check_petal_length(df):
    result = np.array(df['Petal.Length'] >= 2 * df['Petal.Width'])
    
    fail_indices = np.nonzero(result == False)[0]
    print("Records violating this rule: ")
    print(df.iloc[fail_indices])
    
    num_violations = np.size(result) - np.count_nonzero(result)
    return num_violations

 
def check_petal_width(df):
    pass

def check_species(df):
    result = np.array([x in ["setosa", "versicolor", "virginica"] for x in df['Species']])
    
    fail_indices = np.nonzero(result == False)[0]
    print("Records violating this rule: ")
    print(df.iloc[fail_indices])
    
    num_violations = np.size(result) - np.count_nonzero(result)
    return num_violations
    

def check_props(df):
    result = np.array([df[col] > 0 for col in df.columns[:-1]])
    
    # fail_index [0] is not needed, since that stores column numbers
    fail_indices = np.nonzero(result == False)[1]
    print("Records violating this rule: ")
    print(df.iloc[fail_indices])

    result = result.reshape(result.shape[0] * result.shape[1])
    num_violations = np.size(result) - np.count_nonzero(result)
    return num_violations

def check_sepal_petal_length(df):
    result = np.array(df['Sepal.Length'] > df['Petal.Length'])

    fail_indices = np.nonzero(result == False)[0]
    print("Records violating this rule: ")
    print(df.iloc[fail_indices])
    
    num_violations = np.size(result) - np.count_nonzero(result)
    return num_violations

di_ruleset = {
    'Sepal.Length': check_sepal_length,
    'Sepal.Width': check_sepal_width,
    'Petal.Length': check_petal_length,
    'Petal.Width': check_petal_width,
    'Species': check_species,
    'props_positive': check_props,
    'sepal_petal_length': check_sepal_petal_length
}

