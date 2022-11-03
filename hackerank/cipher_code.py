# soal https://www.hackerrank.com/challenges/one-week-preparation-kit-caesar-cipher-1/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-three

# concern k could be > 26

def caesarCipher(s, k):
    # Write your code here
    a = ord('a')
    z = ord('z')
    A = ord('A')
    Z = ord('Z')

    res = ""
    for i in s:
        if i.isalpha():
            t = ord(i) + (k % 26)
            if t > z:
                t = a + (t - z) -1
            elif t > Z and t < a:
                t = A + (t - Z) -1

            # cover edge case when z jump to A
            if ord(i) <= Z and t >= a:
                t = A + ((k % 26) - (Z - ord(i))) - 1
                print(t)
        else:
            t = ord(i)
        res += chr(t)

    return res


test = "!m-rB`-oN!.W`cLAcVbN/CqSoolII!SImji.!w/`Xu`uZa1TWPRq`uRBtok`xPT`lL-zPTc.BSRIhu..-!.!tcl!-U"
r = 62
print(caesarCipher(test,r))
print("!w-bL`-yX!.G`mVKmFlX/MaCyyvSS!CSwts.!g/`He`eJk1DGZBa`eBLdyu`hZD`vV-jZDm.LCBSre..-!.!dmv!-E")
