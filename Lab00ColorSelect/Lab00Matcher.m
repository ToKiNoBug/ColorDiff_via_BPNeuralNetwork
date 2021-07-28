function [Diff] = Lab00Matcher(Color1,Color2)
%size(Color1)=[1,3] , size(Color2)=[N,3] , size(Diff)=[N,1]

N=size(Color2,1);
Diff=ColorDiffLab00(repmat(Color1(1),[N,1]),repmat(Color1(2),[N,1]),repmat(Color1(3),[N,1]),Color2(:,1),Color2(:,2),Color2(:,3));
end