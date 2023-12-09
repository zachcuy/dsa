/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (39.67%)
 * Likes:    7876
 * Dislikes: 404
 * Total Accepted:    663.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aba"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abc"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 *
 *
 */

/*
input is guaranteed to be a valid string with only lowercase english letters

naive solution:
delete a letter and see if the result is a palindrome



*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool isPalindrome(string& s, int l, int r)
    {
        while (l <= r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }

        return true;
    }
    // AC
    bool validPalindrome(string& s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r)
        {
            if (s[l] != s[r])
            {
                return (isPalindrome(s, l + 1, r) or isPalindrome(s, l, r - 1));
            }
            l++;
            r--;
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    string s1{"aba"};
    string s2{"abca"};
    string s3{"abc"};
    string s4{"eedede"};
    string s5{
        "sxgbhujarjjqabzxhpgpojhtbuamilocicridcgzwoelkpxzcrdfdiepxsrjoeyvqbymkpobjilcmlpvojenvoevco"
        "dwresmcwhdskcacirdpmarwsgjzizvggbythkjquyqpelpmaorjkfwlsimhuvlaqusnlueqowcuruewxywttpqeanm"
        "rqdfqjpwadtivuveufexunyeiyqnxikjqilgaaqcjsadghfiwdvqcidbbzpccyzcvqphjwmwduwklwpltbldqbyhdk"
        "eniodgwunolteoxqbqbtcvfenjjefxufrlhjumycpuqiqkxowopezyywgkvwxcsgiknixeeicimlwuedmebjmwvcez"
        "giphmzfffgrvhudsgczjycsahdtipkejkkjkuuxwyrsvpucciaznnmenidscncaaxrvolnkivwkscbimaiwmgeamnh"
        "rfvibmaoadgatawfcpinbrmtiuezxwhusnqlbpafrfvnpafwmlmmaaiazmyzhetqmydipbqotuvpwpefdhjkbprcrq"
        "gizkxaurodpnnhpevqrcunmvgirbkuqsmenrmwdedlpydjvzswwntqjacxnhdqebwbagdvrjdudgzymthnsgzpdxzu"
        "mnlawtfoqwnrwhzjzbprqktbucywfhenzgdhbgjasueivditofopxqnnqmtzyzpzpqvjzocabgnzkeupbfbrajltmo"
        "idouqczvkfjrytnenphfmsgtaogzwriasrtxhcbztlodoxvscdmdbfnfsouaopiatcxbqqjeokumqrbkoubaxelqzr"
        "fkwndwexmmysquebmiarrpkwdjfsiwwqrormtiyzhptitkihweqyufzlzejydgqtlrwvrmfshilwsobhsvdxqtqocu"
        "djqfgbwxympktscixhisdhhimvifvxvcvfjvikvxijggyvlulromuuqcuefvvxiftjlanlqorxtywubqdwgkglewce"
        "qvjvdgxnsaqhybmxvoridljsducdgmuuvmoypjfxbssyghzmeuybpbzmpuuogkmxmnqckrvwdnlhuskyfkqopbqvec"
        "kotmmmikprlakoidwrhzdmedlycxoyysgcseuhdbiyltazaqbuxclycsrxzcwmcvqfjwldtohbvhjgvnbokiafxohg"
        "adtadhtqmltjcfyhjznngqnsoivgbxhulynwwckeedpjbtoqmddssbzomuyjbxghflrepbcngqogxdclqvujzqwwfr"
        "thpwqrqyefodhjsutuhvvtfnwolyzspgvpikuzkrcpwvppbnyorxcfzobcvclslxrxpfltessviyjtcjzndxkxabeu"
        "oualclhpcbfjghjhmeowazowdvklwciturbgoinfmtpljwukdzddffjxievffhjuultovhjurwokzeiyfxuvfhivpj"
        "qufbzsdwjbidbmatcdekemngwrmcnbdclosnyfnemaswplleesftpqodzlrihfwhuopagmclvbjeemvwjegfnzrcnt"
        "huzknhtlqcaxbzlcvgraequcolsqjqttvpjebfpiqpqdmwlcslrhtbhczrknththipwpqagseugvjdbqtdmglgexqh"
        "ithnybqvxfmblzpdvlxqbuteqwtyqgrljvjxpitecdrpdvdlyhenvxvdexvcxqvuqtxugkyusbxbfpckykmimkzuqo"
        "kohqfkbrmeiueiafneydxibmlsvztstcbjmpwlcrxslpwphjzdwadlxivsrftafykvyeoshrwtxaospinawybqoyig"
        "vwhyheikxbjqsiqwkehzzbblhkaephipssaqguipmopyuumuvxbvfdwjqzlomckfxrgxkyipjrmutoflhnyfgdbrrd"
        "tjxyvydhtxewgmmbmjhxgonumbjdssggikcjrlvfxsgeewatzmcldmdhnomdolffkgfecahnqvfnoimqppwuqbpjgc"
        "aswcscvvfuzemtprbxkqgdqmjdbrjetivsrexpddujilhmrrxdjlaqgbsktfokjpkmvmqsrfxdjjvflnesxdaqlzdj"
        "momkbzpqbfwwungzufbhockfbkpbmxxhrcgswyqzjvskescdqonmgnajcbproqcvadoromfuwnfemfsjmhrqmdyqqm"
        "zjerhabicpzlbodbavtkjwofeuqeffwpfsbrormyexsugrtwpqisjydzzjeovrowbnvhpcpuvberhhavlkgmugkoju"
        "gzutgbbbcdryqlesjmryvowcwwhgwfadrazfxumnduanihfyccwuuogsfeehwiqnspafrhgteakxncidhxctfihdxg"
        "ovbpuhgupeydguaypyjgvjmyosatxpsglkdiffihcrdfosllvhwqrkygcsqvehguutqjmkpdojneqvlcwjlqmgliyc"
        "jigukconyvxxfzjzukhixkkgqmwgtsawhxxvmgwcvkzvlbumasbmrzkzytxzprincuvoqlvtymarulnivhlfrtmido"
        "pouksspxgdedazonjtwjmrsnapcsklpgqbszbzbewvrgjmcnvibviqvfnrtxgzjnsuvbwvroqvwlvqaydgrfgtumdx"
        "icczupjpmrqpgjojyneoilymsaytzgnmyrupokcgahkpqnioyxtaidjylvqkwrdflctlryktouhtjneeaxzyeeahcb"
        "zyhjbwatsxforrzgfwpaxqjedllmioroaxtqoisiaxfjorxwsdvwoxraxswmsogshimivrsgaoqihknevhrttosymt"
        "htxtzywntfaqvkwxkvzytwphecvxopncsejwpusomrioufnqrtktdsywhlweufugshzanlnofflpidhkhbuutdvkur"
        "kkchpqqzmtvllyovvzkigowxxyudnzbbtubhfywricbidvfxczmbstxfnbyzzidavlpeowcfqcqvdpepuwnwrgaltq"
        "ztocetvlkvflcfafiskxlzfubjowvutqvplfbjiajfgpnnrksdjbwztxsputlxsoxqaldfciacbhnxoozdyhvlodcr"
        "tpqjbogyzfjgjoujckymjurywvdauuslgmkhozxntpthociytyxuuvyrpsnngkbrztqmgvfbxllbxdoacqkbttgbzi"
        "uaorbknclzkfjenozdefbmmuzeopjrcxbqhottirqoocmptuksebiodyfnlsqjkrugygaqvypuyvqjrqingquyzjef"
        "hayofxjnjhetpxzhntqeqtwxagmarwaajxwljxzbpljhthqchkcdxmwuwzddgbyomqhxtproekdnpexagxmaqjhvnm"
        "hrlnannzeexsxkcoxpvmpjrgbvrqcnmnljtkjbibxokotwgzlhxgyxzqpjgmfjycidhgjbtyzulsmafyyjiheizsos"
        "ctbgjamtqlmtkvslkpmrlozbbdhlsacmzjqluomvosdtulmehpipjuyzwitvcwlcceninbsejdlwfesljufmftvvun"
        "yktainxirlobsertlhydibztsyshlgizemalfwrtimhzvqtiacnyikhmiadvpbehzohqzrbvwayhsxxzchsirrtuyo"
        "ywjbmfbxfkpqbssmrkmhxlbwsvcicefzdrlkhkkhbnprodychldqurdjbgoawvznrnogletqkzaxumimegpkelzbhc"
        "hoknqhqnnpjyjgvamgsmoioscmjtgnwnjglwhsukzzfjerqubkvezjlrqqatdkgmnxzbvbsgmithvnioeynkunqquk"
        "qerhfdptumhgllfgpvzcrlnvmebafrbmkoatpzydkhgnlfmcrxzpvqcpyjhykbqvohhgtfhkoprofcbeeccfzemofa"
        "zrkekuguwnzqtfksdbbcibjmqfjhiugkzkazzcctbkgwfbmpgetwntdrcmkapwceubbfuvkwqbeinulgnaqhddhjhg"
        "mogjcoidvvjphiyvlrbddofaxudpcpzuxmhbutydklsezlwnalfjtqppduhcnfpbrrrnglmspzkjozjqstircvxxlf"
        "qqdxghaftdauxboycpnhusgsxtxfztqnffgqbkqsljrexwfnyzyeydrpnrxoytzdsbjrlmzthnddhakgfpaqcjxckt"
        "dljnywxdotywdjflyyavpbttewwixetzgboepfulkwcqcopveuhrkiszmfeyjjutfosmlvydcsjrfspbxntgwtpsba"
        "vslhvthxepoquzcdkhbpotpcfkjclmkugmxdfunpulhniqsbhrldzygmstrxrozbusgpvpbwtguozqhqettfaahiox"
        "ysclffjagedsdaqwclolhruhnhvrjrnxpsgbzskutowjbsfbhlobhymctnxbnrpkijnkzugxwluzrnbiicjnvhldec"
        "cvjqnihwrvvaozcpqrckwgjrzupkjgztwvkfdwscklmuxucbjajnljcisufmdyshyvoanmdrwjnnumeknqagevetbn"
        "ututlrwdgtpfslzbajfenhqhygfzsiaqknvxcorfekarrrpqpgjaltitensbiusvdrevzoprigjsbsgsvgekcjmloz"
        "gjylwftqqfqmsdkakwfhazbwdycvukfamojbuelomqrdmnrtiworqipuxlkweglfinjusnnhknanwyduycmgirqmjp"
        "tnqkupdgmavkuqgtfiseazioosacyaqrgfjzwcwpvrhcnilaenregfttmzzkpupubzgbmyukcdbijtzlbtamvkdpuc"
        "flgcpvjlszpjaoluiqxqhqvdkhmhfzjvlrienovnuchzdtaztryybfwahxtibjflxohiameksqhmvzbjemiyomeray"
        "jcmwiomrnfamcmbtrcmjxkrlonmlvovjoccvufivbushiutivoafyvpelzxeupsqnhnlosgcpbrbsegqowojkwuxck"
        "vzgofgaguuyvpsubcqdejhkiywxtimaunrjpifbwetguwbjoop"};

    dump(obj.validPalindrome(s1));  // T
    dump(obj.validPalindrome(s2));  // T
    dump(obj.validPalindrome(s3));  // F
    dump(obj.validPalindrome(s4));  // T
    dump(obj.validPalindrome(s5));  // F
    return 0;
}