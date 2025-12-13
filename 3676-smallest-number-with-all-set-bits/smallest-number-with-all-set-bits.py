class Solution:
    def smallestNumber(self, n: int) -> int:
        """
        Find smallest number >= n with all bits set (only 1s in binary)
        Examples: 7 (111), 15 (1111), 31 (11111), 63 (111111)
        """
        # Find number of bits needed
        # bit_length() returns position of highest set bit
        num_bits = n.bit_length()
        
        # Create a number with all bits set: 2^num_bits - 1
        # Example: if num_bits=3, then 2^3 - 1 = 8 - 1 = 7 (binary: 111)
        all_set = (1 << num_bits) - 1
        
        # If n already has all bits set, return n
        if all_set >= n:
            return all_set
        
