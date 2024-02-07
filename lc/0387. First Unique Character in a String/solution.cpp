#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;

public:
    int firstUniqChar(string s)
    {
        queue<int> fifo;
        int alph[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (alph[s[i] - 'a'] == 0) {
                fifo.push(i);
            }
            alph[s[i] - 'a']++;
        }
        int idx = -1;
        while (!fifo.empty()) {
            int tmp = fifo.front();
            if (alph[s[tmp] - 'a'] == 1) {
                idx = tmp;
                break;
            }
            fifo.pop();
        }
        return idx;
    }
};

int main()
{
    Solution solver;
    string s1 =
        "uindrseqbljlhqvlwvgdebeihttirikuahlikgnahvgnptmqwbovmuwesxkvcitcwrwruc"
        "sbbfqvldridfviduqvmfcmeiphoqupbitnwdbvevouoaetisdmgvvvwoglwtgjrpcbghxk"
        "rkjthetxeexbphbjiehaicuicgnirslhdstgmqcdnlulpdpadjdltfouwhfqicfcqntnpe"
        "qaohslwkhbvflxaudembsrsindluthxapnmrqinsivbxmkohubvmmmpmklbfrmeuvdrhpt"
        "dmelmjjefgbsqqlbqhvsmswwxrlkutadqbbeisbgfrcivvoxmxxptrscxnjjvtajfhqiuc"
        "dihihcutxhlonlomfdnbwanrcnbarojsajseqrgkuqgkcnvrghxnmbclfomktwfaakodee"
        "csglufvobkgoqsbrhdiuhxqbcndkmxuertupngvnkgwrfwgdbiurbooxariklwarjgavsu"
        "ddoveipltessrssxwxgvrrtkisnbavkbpaphicxhapjjpkccakepuafjdaswfwfmbdmuua"
        "veukxvnpkgmhcjcpqntssthjlvrngugbhrivtwmbrvrprrlfmvwjdkonfmgnepqoxwfcve"
        "fjihisarwskjfmqrjlkbbugfawmkqgfxgpokkxxivqbqimwsccdekjegwcxhmmuhpstxfp"
        "ofwmrmhrxeptxwbvxsesheijjfsshgrrwckjkmbslpbngnwhokjnujtiepfrdhiwwgbffi"
        "xaidabacaibummwxgxowsewlqfxrkarjrkqxmxwobqbcoowmbggtpoqadhqdxlhvxrkfuw"
        "pxxgnchudreoeuefkqhlrmwwfvjexvbxdhtdngwvoohpjtdbdbesceiafrhenfljleegse"
        "ncfmbauxlltfueudnjxsiiggsfwiuidgktsbtcvxtdllviocfdbonjciosucbjidwxnogm"
        "nveqkcrxbpamfxwxiugjgrfpstromuxxdiodqeoqdlfulttraquskhwfholbrcbchijlgq"
        "vuwxvejedikvgetlmrcmeampdgjvmbdovkcjilbralhmniwvbeandldnudkpjvhoqtfdwl"
        "lridwljfvflfdrbqadvabggwsiexrthrngexpebuhtefkqgkkjoopsmunesfotsprxuasw"
        "wenhkdvsspkppulecahkkvccqngeaoijjgvsfqfpvphvhdnkkcqsebhijkvfpqjmarbkpe"
        "jagtbtisnflrrvawmvfxeccxtrmorihgslxlqrqcmouojjfhcieuwlrcqhevmveookgonx"
        "qdbtgqjimsidnaaiuchwkfkpxfptuvhfqemojixqvhgokdekdwbomptqqlfiaiptxvgfmo"
        "vdqxupjxjpoxuplsagxpgpmvtcpawkrrthvclhdbpqeucchxptdceswhnqocmeocpgthkg"
        "xmxggwlnantwwuoqpmnpvgateitxlocmhnihmfgjnvrggenbhnjfubtoteojojjkjpcnwq"
        "thxhlfukingjletwnxdnjwrgjopqoxtqcvwsakqxxumbtcblufdmdvxfkshitenmenkxjv"
        "blsoiyhjpakinimwxhcebabgsvqftfvwjnstltjawhwipkubadtoxqrutkwxjnmfoowtnv"
        "qplvqokcuwlkmxxhboampcdwokjfxggtnojebagxlwaeowtomubtbfsrufkttugfpnxmip"
        "kcsphqafjuxovwpcgonhiqmomsweunoeqkpkxxsdksmufowqpmkontccckcdbwrfwamika"
        "nanakgjkahndrepemcgxecgpltvdbpoexemnrejdephuuxhfcubxlbdrmhvmeqmtdhnbkw"
        "nidigxdantmkckijiecavkpumegrbveffclcltmibjcstrrauphfxxssgxkkirapiihnlb"
        "rodvfostahqdkajqtrrfwdsemwxlucbbjjspnnqjnpnpmimhulgoskwpsactexmkfdhaih"
        "nlggqeunqevxfrpiwskhrhgfluelshqejavomjshfomvgpugqesbtakvxqwrtguuebcgqp"
        "hocglfrircfvuikfbviomfrsnpvvlftwrkbmjpvdpgvohtmxcxwnuhwojnfvsfwvdlaxxl"
        "mafihpussffcawjpaxdwerwfbvsbipljualcnhseealvqiqfiaiskaafufaubvhjglktfh"
        "bdsaskmedroxkrxshnggumcbtdcablawkodmnafkjekuiecqlvbxocfcwipaicgndfafjh"
        "tjcelakrecmntjxeqjqgxkxapuobbcaxfrpsktjswxdfvugmmgjwiphnsclqwmranthpiu"
        "effaxvhplajqsrtoxbixbdpcfkbpkjkelemubwachcpxcniaqmkmasmvlfcubcdkxfkupg"
        "cgbrvmbmgnjgfbawmmdritdrkppswatwtdjemhifhmshunkvaivhteqnwkdcrpfxmrafup"
        "fhbgligbvrqjkvcgbiqudvtblhfgetffduvsfhsmjimgruxrvbqniluapaoniwhqhltbxv"
        "rphmlisfaomqoecmdbbrgujgsbdelkbddcgmpggogfonssxisphbwljlvhwhewmpqugxgb"
        "ubqfeilobxxhtcxmxvjtbuavxlaghhjiemihvrsjxbleutpuumgndtnocwkpkdaupbmcsa"
        "hcbwoelmgnwqummmekwhpahtdvehoprfcciwqphfwppscruimikiximhbkdomovbdalsih"
        "ioncpaclevxawqcqthtmuogolkrvlipropmnmecttmlecpapdlrcqxopfjobgsvhcadqiu"
        "dqjoscpvjguddnorldkpqtoocrtkcutkvdpbkkekenpqjmxmuxccamkwwxrdrbdmameptv"
        "cgsltqdasicoouvdtbranexokmtkioptqblrruaihvfvvebjigkuwwgearxvmimlgmxgpv"
        "bnotepprknjxcunheclsvxxmmoufvdhrwxqlrkmvcaxtbiqrjrnrsfrkvttnpxbspnetco"
        "fhpcbcphrchivnrskkalsvdllhtisnaerxbcxutcpmnquwrutmmvrtchhheplhdmbfkrrr"
        "xalosjbebtdqtsjbdcuuatgldnubigijbkehxsmhsadwtcbwinlnilthiqslvsduspkjuu"
        "npetcofujbqhtkmalnjmllhulckqodbgffxdiqjajecbmlekvepkirxnguqnpnfjdptinu"
        "phcoxkoqhqrmkkawmngqwvfpcuxgpekkprupplsbwshmsduaitlhcjargacduewtqgnxbt"
        "pwrkawpncarxlsnardkftmsdjflmhoplghandjisupacixxthwokctbxekqwbmhtoutgro"
        "gxsdnmcaqrsqrpigbigqhsmrksxgkdbdbxkwimpehltcffuhrphbaqgvabjduudbrxgwil"
        "jkwijvaugnleamskjijhnvcspagsfnhjielrvxddxqfgaipfflffksmvgaioaclfsjhovc"
        "otoaiwhhnmrudsqmsepsgdofnxjjcgdejutmdtgauuvuepajlikebtpgfimudswplfwgao"
        "dtwqjuaujlbqqartevsqesmrpknoanfprqcwochqdrcvquovtsogptduvfiaislfvpxwsq"
        "itodxwckprpfxtqhbdixklhtsajqgbinfpdqaehrwhnwggmggnbstolrcbmlhpfjurbknp"
        "wbrfhvdanrjcwnvsxudagbkhdlwujqvwpbbgmsfrkgutkqwxqfemaaokrfdocsbbktwaug"
        "oadgvqcdhmqkworbvxqwdpmbjkqghmapevrsnaaparwnbvcfnhhgfqplfwiswrxxistamu"
        "lcbxcmvkbcxsgftbmbvqlxrhbmcujkktdvcgnjkfaclxndtjkdbgqvbqxicgmpowbjsfvs"
        "pvxtrovjwbbkaapfgcqbifdosnmutvfbgdmhiqvflasedhafqnmrlmwbuhmptnkvvojnjn"
        "giepmdktewwsuxernpfmktsgwwnxfvmuotpfxfntcrsjpldmringfpkpievvbgbghevlmu"
        "ticukrfvahrmtkvckjbxxrmkilbeojsxgbvbhsgvkhgtjddoreipbkwiqbkecobfexswiw"
        "ttlohnfwokixfmfrpadtudrssiobbvhctpbeesiogwhdqojoalxpxikwuheilvsrxbfbnc"
        "kjeswhkfviihvwrfxkxcomhvsjojhltospooumkstqqnvxmrowlrtufhxkipxnfecchklr"
        "qljfwnglxeharemawsbvnuentnapewjhnzbieisjtomdqtjkigisgopmgcfqxcxninrisu"
        "pchhmfrosxgdtakhrrnbbnxovvbfjgwdgnlxoxswhsfjeijvivqemoekkmrttscthlpgla"
        "orarhibrucuhikfkphqmhowloobeumlikqmmlatesupiekwjhdvntnjbakohrbobimmujk"
        "batfxpmgfmmqsgwsffcbenwgdrhlqrsmfghevnjfdlxupihmkptsefubmixhacnxngpjrc"
        "kxhvhrelolqwevoqklhxbplakmsxdetvpuddmvaodpglmsknbvfftstckjurbntwqenuhc"
        "urxqvotrxfpootqkobeatoduihwhpjxxrvboggkcxagnrrfwfuaqplirlnafprumnkcjxl"
        "pvanfmqwuoaupqptqeulpwvnhbahbkihustenkbdushjakemufdhjllnowmvgpdxbrhxfo"
        "npgcjslvwgdmajicqqmdxubrofvdodfsedjghpbjncgkckeudxwascljlraoodwvgpvojc"
        "qgbalntslsfrwnfcdvidsdrvwhscskpalubxeobapkgpdsqcjpwkednraijmbcreplwijo"
        "fniggavpdlwfmwnvsaridhbppeolakquhamneffnfmbruivassdaaikxiaxupgdpgkfojv"
        "kkagcsmqnweofwikvevrsottkbtcldoruakajinnlgxmpddcrmohaktsdrxjelrbmfdths"
        "pikxeocqqdordrqwjtaxihswcubtfomksaxddcvtadnrtqkmdnacgduudtdbhsgpfomrdi"
        "aotcfwqlxccqeelgtnkflgixpjcriroruhbbgpidwkggdevpfratqebewaxcudseaikqju"
        "uhpsguvtwxniofskkslfnrphatmxngneuituefcxufisrsjitqxwufrgidbwlmkrqojpwp"
        "ljasaiukwwthrudhcocoguerakhajdncxbrnuavoqeuwsamwdqgutbaoixcgeibpoajhed"
        "ooqcewiqvddedmanxljjjcbojgbmwabkfbvamgnfpncdcxoaqhmgurifpwpgrpctlqpwmq"
        "raknjltneknsphtwbnbiahknxipsovljkivlpggvldeveeopvoqlvfjbratadttlcecoml"
        "lpkdgiloeedquivsnmxkfcvrkwaohgbrbvjklkktgwtlfgafqgbigheajrvffvvkkmibce"
        "dfmnwasopoqgxjohjoqnijeaifuwiwmogkwqlfmibuwecvnulvhkbsukscqlqlsxjulill"
        "mlgjkrbmllcunhbqmbujftqgkpwkvemthigednfohxpsduotwfnknfjbexflcfieaosnlh"
        "ndsorbkcdlahovwbccshmrlcofowrmqajluiqaarnqtxokbaddswftiexiahmstpbonwmh"
        "vqgcpmfrocvtwfhjrtsupscfmvwfvaoolanrlgdsvgoseltdnoxrdglockhwlvffaakgrx"
        "jfnfbxnbprfvpwmexnhfekjnkenbohhmwlqoteiwgtjsrnceptbgwkfcmtkliwwqskmsoi"
        "hmnbjsvnmfkwbwemijdtpnajgrousbrdaagenqlgeaiixfgcbfhceaxkwxbpksfouuqcvc"
        "erqecpdtvtsubbadmaatdnmnqhladeiapejkxffoagbwqbvppssvvvhlvhntatxlvqgjxb"
        "ejpvxemqbdjknuogumrwbognklmvjsldrktpeowiuaapbjgktxwfjiferxgmafbcerteql"
        "vpqvxbgdwiufdctkwptadtujmifppudubpmdtiedmqhnihquansnjufpbuumhhmidphkwu"
        "sjdsdaocavtauhsvtgcoqhufmacwcbxvjmagkounkoqpcnoanhgwsjvgtlwgvbpdbufeko"
        "sgagfsmadmvbonkrtcbspoabugkcjeebqhqwfjcqlqjvabaqecofgwskqplgup";
    cout << solver.firstUniqChar(s1) << endl;
    return 0;

    // Following tree
    //              - Null
    //       - 5 - |
    //      |      |      - 9
    //  1 - |       - 4 -|
    //      |             - 2
    //      |       - 10
    //       - 3 - |
    //              - 6
    //
    // TreeNode two = TreeNode(2);
    // TreeNode nine = TreeNode(9);
    // TreeNode four = TreeNode(4, &nine, &two);
    // TreeNode five = TreeNode(5, NULL, &four);
    // TreeNode ten = TreeNode(10);
    // TreeNode six = TreeNode(6);
    // TreeNode three = TreeNode(3, &ten, &six);
    // TreeNode one = TreeNode(1, &five, &three);
}

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

template <typename T>
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
