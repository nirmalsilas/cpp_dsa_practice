
normal recursive_function
--------------------------


return_type function_name(parameters)
{
 if (base_condition)
 return base_value; // Base condition
 else
 return recursive_function(modified_parameter); // Recursive condition
}

return n * factorial(n - 1);

factorial(5) = 5 * factorial(4)
factorial(4) = 4 * factorial(3)
factorial(3) = 3 * factorial(2)
factorial(2) = 2 * factorial(1)
factorial(1) = 1 * factorial(0)
factorial(0) = Returns 1 (Base Case)

