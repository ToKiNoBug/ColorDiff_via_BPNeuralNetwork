function [Diff] = RgbRot(r1,g1,b1,r2,g2,b2)
%所有输入必须是列向量
r1=r1+1e-10;
g1=g1+1e-10;
b1=b1+1e-10;
r2=r2+1e-10;
g2=g2+1e-10;
b2=b2+1e-10;
L=max(max(size(r1)),max(size(r2)));
sigmaRGB=(r1+r2+g1+g2+b1+b2)/3;
S_r=min((r1+r2)./sigmaRGB,1);
S_g=min((g1+g2)./sigmaRGB,1);
S_b=min((b1+b2)./sigmaRGB,1);

theta=2/pi*acos((r1.*r2+g1.*g2+b1.*b2)./sqrt((r1.*r1+g1.*g1+b1.*b1).*(r2.*r2+g2.*g2+b2.*b2)));

temp=abs(r1-r2)./(r1+r2)+abs(g1-g2)./(g1+g2)+abs(b1-b2)./(b1+b2);

Str=abs(r1-r2)./(r1+r2)./temp.*S_r.^2;
Stg=abs(g1-g2)./(g1+g2)./temp.*S_g.^2;
Stb=abs(b1-b2)./(b1+b2)./temp.*S_b.^2;

S_theta=Str+Stg+Stb;

S_ratio=max([r1,r2,g1,g2,b1,b2],[],2);

Diff=(S_r.^2.*(r1-r2).^2+2*S_g.^2.*(g1-g2).^2+S_b.^2.*(b1-b2).^2)/4+S_theta.*S_ratio.*theta.^2;

Diff=sqrt(Diff);

end

