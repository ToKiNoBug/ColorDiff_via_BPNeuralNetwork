#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#define tansig(x) MatrixXd(2.0/(1.0+(-2.0*(x).array()).exp())-1.0)

using namespace std;
using namespace Eigen;



MatrixXd W1(8,2);
MatrixXd W2(8,8);
MatrixXd W3(1,8);
MatrixXd b1(8,1),b2(8,1);

MatrixXd b3(1,1);

void initializeWb()
{
    W1<<-0.7379079229650955529251632469822652637958526611328125,4.15959501752493121529141717473976314067840576171875,
            2.11981494981134499511199464905075728893280029296875,2.880071871995810273148208580096252262592315673828125,
            -2.1055788669376145350042861537076532840728759765625,-1.0494927092910597554720197877031750977039337158203125,
            1.7301835012476673991699271937250159680843353271484375,1.543342754666643390493163678911514580249786376953125,
            -1.324335628998654090793252180446870625019073486328125,-2.127338597794576902089147552032954990863800048828125,
            0.691579536812907402776318122050724923610687255859375,-0.77401470381179493518430945186992175877094268798828125,
            1.7235579404496237376775980010279454290866851806640625,2.848984575387751849717687946395017206668853759765625,
            -5.72526774378643832363877663738094270229339599609375,0.437061930239823592803105611892533488571643829345703125;

    W2<<0.0492544981875524257031173647192190401256084442138671875,30.067364599492133692137940670363605022430419921875,0.422805670361345420360521529801189899444580078125,-3.05510874082955918851212118170224130153656005859375,-4.9473480202878050704384804703295230865478515625,6.925628708478615891408480820246040821075439453125,2.48818088050570462854693687404505908489227294921875,1.3696196758966687756498004091554321348667144775390625,
            -0.175667431436628052043857906028279103338718414306640625,0.218013570959803726356796005347860045731067657470703125,4.525755016652379225661206874065101146697998046875,9.49428256072803122833647648803889751434326171875,1.18917185508054767950625318917445838451385498046875,4.721051306832674043789666029624640941619873046875,1.5272551442929798160008658669539727270603179931640625,0.30848199990543034854084680773667059838771820068359375,
            -0.05744705729571784880160834063644870184361934661865234375,-0.76839089008220839982499228426604531705379486083984375,-0.88091592441733335139275595793151296675205230712890625,2.340313339738580911131293760263361036777496337890625,4.50668551328675537348544821725226938724517822265625,-6.5726613325991625202959767193533480167388916015625,-2.362152481579264051703148652450181543827056884765625,-1.244752883421820666143275957438163459300994873046875,
            0.834820463269763113345334204495884478092193603515625,1.63363684725860469626468329806812107563018798828125,7.700491932165544284316638368181884288787841796875,12.5579681976449091251879508490674197673797607421875,10.900684643683508312506091897375881671905517578125,-2.779814864846942068510315948515199124813079833984375,3.087141298212417783730643350281752645969390869140625,0.328336460249105288600190988290705718100070953369140625,
            -2.16912125025686552959314212785102427005767822265625,24.49189807799989893055681022815406322479248046875,-0.9576856373148368017922393846674822270870208740234375,-2.751096614032366272084573211031965911388397216796875,-1.2489403047942666535874423061613924801349639892578125,5.4560993200830250060562320868484675884246826171875,2.9028020521471038506433615111745893955230712890625,-5.9907432449578532640543926390819251537322998046875,
            10.1482989255598834432703370111994445323944091796875,4.73801209780028731444190270849503576755523681640625,9.2943139693110605747961017186753451824188232421875,15.946380090861200784502216265536844730377197265625,4.47429774752167563889315715641714632511138916015625,5.2094534258541127513808532967232167720794677734375,0.340043763721741776340223850638722069561481475830078125,0.6255223410979227072203912030090577900409698486328125,
            -1.03923855815309007510904848459176719188690185546875,-16.402511281911788643128602416254580020904541015625,-1.9952640475023699639933738581021316349506378173828125,-2.99442709519820748909069152432493865489959716796875,-1.256280050476949572413332134601660072803497314453125,-2.946024092910383362919901628629304468631744384765625,1.61490287046865876874335299362428486347198486328125,-3.146822655668378931892448235885240137577056884765625,
            1.828965047187922632332401917665265500545501708984375,13.7938707891763439050691886222921311855316162109375,-5.98173615009006365283994455239735543727874755859375,-11.3578735515016102652907648007385432720184326171875,-5.56273808037604755583060978096909821033477783203125,0.259453486669464605807178259055945090949535369873046875,2.4922574385955869047393207438290119171142578125,-2.27418836061378470958516118116676807403564453125;

    W3<<29.90187420492704717389642610214650630950927734375,3.5484653900326748043880797922611236572265625,34.17311495598854520494569442234933376312255859375,1.197754565569055795748454329441301524639129638671875,-2.05360186226218832672429925878532230854034423828125,1.8775904506273863869836304729687981307506561279296875,-1.9462522211426069862483245742623694241046905517578125,2.7392374679800806092089260346256196498870849609375;

    b1<<3.535243032526664830328400057624094188213348388671875,
            -4.74250197594118194643897368223406374454498291015625,
           0.85438355370276874989343696142896078526973724365234375,
            -0.619546087098354458788662668666802346706390380859375,
            1.038646428816512479187395001645199954509735107421875,
            1.14739821875605851886348318657837808132171630859375,
            0.9626933332760863049060162666137330234050750732421875,
            -5.31433308976256402189619620912708342075347900390625;

    b2<<27.840313994275835085545622860081493854522705078125,
            1.6653975124141080499384770519100129604339599609375,
            1.4955783200015020373285778987337835133075714111328125,
            0.55597144532617981393940453926916234195232391357421875,
            12.1842733638377840321709300042130053043365478515625,
            -12.8688225668294737857877407805062830448150634765625,
            -16.045664116371955998374687624163925647735595703125,
            10.0378946902186090284203601186163723468780517578125;

    b3<<-1.3741243314987574564156602718867361545562744140625;
}
/*
auto tansig(MatrixXd x)
{
    //=2/(1+exp(-2*x))-1
    return 2.0/(1.0+(-2.0*x).array().exp())-1.0;
}*/

double sin_mult(double x,double y)
{
    Vector2d I=Vector2d(x,y).array()/2.0-1.0;
    auto res1 = tansig(W1*I+b1);
    //cout<<"size of res1=["<<res.rows()<<','<<res.cols()<<"]\n";

    auto res2 = tansig(W2*res1+b2);

    auto res3 = tansig(W3*res2+b3);

    return res3(0);
}

int main()
{
    initializeWb();
    double x,y;

    x=1.0;
    y=1.0;
    cout<<"sin("<<x<<"*"<<y<<")=:"<<endl;
    cout<<"Network result="<<sin_mult(x,y)<<endl;;

    cout<<"standard result="<<sin(x*y)<<endl;

    return 0;
}
