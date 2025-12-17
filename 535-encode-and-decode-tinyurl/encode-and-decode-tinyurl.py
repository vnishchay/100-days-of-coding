class Codec:
    mp = {}
    i = 0
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        self.mp[self.i] = longUrl
        self.i+=1
        return self.i-1



        

        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        print(shortUrl)
        if shortUrl not in self.mp:
            return -1
        
        return self.mp[shortUrl]

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))