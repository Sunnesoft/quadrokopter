clc
clear

path = {'e:/projects/quadrokopter/true/',
        'e:/projects/quadrokopter/noise/',
        'e:/projects/quadrokopter/filtered_lin/',
        'e:/projects/quadrokopter/filtered_transf/'};
timelim = 210;
fns = {'accel','angvel','angcop','poscop'};
[e,N] = size(fns);

titleGraph = {
    {'Показание акселлерометров:X',
    'Показание акселлерометров:Y',
    'Показание акселлерометров:Z'};
    {'Показание ДУСов:X',
    'Показание ДУСов:Y',
    'Показание ДУСов:Z'};
    {'Крен квадрокоптера',
    'Тангаж квадрокоптера',
    'Рысканье квадрокоптера'};
    {'Координата квадрокоптера:X',
    'Координата квадрокоптера:Y',
    'Координата квадрокоптера:Z'}
};

titleVar = {
    {'Дисперсия отклонения ускорения по X',
    'Дисперсия отклонения ускорения по Y',
    'Дисперсия отклонения ускорения по Z'};
    {'Дисперсия отклонения значения угловой скорости по X',
    'Дисперсия отклонения значения угловой скорости по Y',
    'Дисперсия отклонения значения угловой скорости по Z'};
    {'Дисперсия отклонения крена квадрокоптера',
    'Дисперсия отклонения тангажа квадрокоптера',
    'Дисперсия отклонения рысканья квадрокоптера'};
    {'Дисперсия отклонения положения квадрокоптера по X',
    'Дисперсия отклонения положения квадрокоптера по Y',
    'Дисперсия отклонения положения квадрокоптера по Z'}
};

outFns = {
    {'accX',
    'accY',
    'accZ'};
    {'dusX',
    'dusY',
    'dusZ'};
    {'rollCop',
    'pitchCop',
    'yawCop'};
    {'xCop',
    'yCop',
    'zCop'}
};

result = [;];

h = figure(1);
iter = 1;

for i=1:1:N 
    t = load(strcat(path{1},fns{i},'.mat'));
    n = load(strcat(path{2},fns{i},'.mat'));
    f = load(strcat(path{3},fns{i},'.mat'));
    f2 = load(strcat(path{4},fns{i},'.mat'));
    
    result(i,1,1) = var(t.ans.Data(:,1) - n.ans.Data(:,1));
    result(i,1,2) = var(t.ans.Data(:,2) - n.ans.Data(:,2));
    result(i,1,3) = var(t.ans.Data(:,3) - n.ans.Data(:,3));
    result(i,2,1) = var(t.ans.Data(:,1) - f.ans.Data(:,1));
    result(i,2,2) = var(t.ans.Data(:,2) - f.ans.Data(:,2));
    result(i,2,3) = var(t.ans.Data(:,3) - f.ans.Data(:,3));
    result(i,3,1) = var(t.ans.Data(:,1) - f2.ans.Data(:,1));
    result(i,3,2) = var(t.ans.Data(:,2) - f2.ans.Data(:,2));
    result(i,3,3) = var(t.ans.Data(:,3) - f2.ans.Data(:,3));
    
    for j=1:1:3    
        plot(f.ans.Time,f.ans.Data(:,j),'-m',f2.ans.Time,f2.ans.Data(:,j),'-r',t.ans.Time,t.ans.Data(:,j),'-g',n.ans.Time,n.ans.Data(:,j),'-b');
        legend('Скольз. средн.(лин)','Апер. фильтр','Истинн.','Зашумл.');
        tt = xlabel('');     pos = get(tt,'Position'); delete(tt)
        tt = title(strcat('Рисунок А.',num2str(iter),'.- ',titleGraph{i}{j}));
        set(tt,'Position',pos);
        set(gca, 'XAxisLocation','top')
        print(h,'-dpng',strcat('./results/',num2str(iter,'%03d'),'___',outFns{i}{j},'.png'));   
        iter = iter + 1;
        
        data = [;];
        data(1,:) = result(i,:,j);
        data(2,:) = [0,0,0];
        
        bbar = bar(data);
        colormap(summer);
        grid on
        legend(bbar,{'зашумл. от истинн.','отфильтр. от истинн.(лин.)','отфильтр. от истинн.(апер.)'});
        tt = xlabel('');     pos = get(tt,'Position'); delete(tt)
        tt = title(strcat('Рисунок А.',num2str(iter),'.- ',titleVar{i}{j}));
        set(tt,'Position',pos);
        set(gca, 'XAxisLocation','top')
        print(h,'-dpng',strcat('./results/',num2str(iter,'%03d'),'___',outFns{i}{j},'_bar.png'));
        iter = iter + 1;
    end
end

t = load(strcat(path{1},'angplat.mat'));
n = load(strcat(path{2},'angplat.mat'));
f = load(strcat(path{3},'angplat.mat'));
f2 = load(strcat(path{4},'angplat.mat'));
    
resplat = [];

resplat(1,1) = var(t.ans.Data(:,1));
resplat(1,2) = var(t.ans.Data(:,2));
resplat(1,3) = var(t.ans.Data(:,3));

resplat(2,1) = var(n.ans.Data(:,1));
resplat(2,2) = var(n.ans.Data(:,2));
resplat(2,3) = var(n.ans.Data(:,3));

resplat(3,1) = var(f.ans.Data(:,1));
resplat(3,2) = var(f.ans.Data(:,2));
resplat(3,3) = var(f.ans.Data(:,3));

resplat(4,1) = var(f2.ans.Data(:,1));
resplat(4,2) = var(f2.ans.Data(:,2));
resplat(4,3) = var(f2.ans.Data(:,3));

titlePlat = {
    'Крен платформы',
    'Тангаж платформы',
    'Рысканье платформы'
};

titleVar = {
    'Дисперсия отклонения крена платформы',
    'Дисперсия отклонения тангажа платформы',
    'Дисперсия отклонения рысканья платформы'
};

outFns = {
    'rollPlat',
    'pitchPlat',
    'yawPlat'
};

for j=1:1:3  
    plot(f.ans.Time,f.ans.Data(:,j),'-m',f2.ans.Time,f2.ans.Data(:,j),'-r',t.ans.Time,t.ans.Data(:,j),'-g',n.ans.Time,n.ans.Data(:,j),'-b');
    tt = xlabel('');     pos = get(tt,'Position'); delete(tt)
    tt = title(strcat('Рисунок А.',num2str(iter),'.- ',titlePlat{j}));
    set(tt,'Position',pos);
    set(gca, 'XAxisLocation','top')
    legend('Скольз. средн. фильтр','Апер. фильтр','Истинн.','Зашумл.');
    print(h,'-dpng',strcat('./results/',num2str(iter,'%03d'),'___',outFns{j},'.png'));
    iter = iter + 1;

    data = [;];
    data(1,:) = resplat(:,j);
    data(2,:) = [0,0,0,0];
    
    title(titlePlat{j});
    bbar = bar(data);
    colormap(summer);
    grid on
    tt = xlabel('');     pos = get(tt,'Position'); delete(tt)
    tt = title(strcat('Рисунок А.',num2str(iter),'.- ',titleVar{j}));
    set(tt,'Position',pos);
    set(gca, 'XAxisLocation','top')
    legend(bbar,{'истинн. от 0','зашумл. от 0.','отфильтр. от 0.(лин.)','отфильтр. от 0.(апер.)'});
    print(h,'-dpng',strcat('./results/',num2str(iter,'%03d'),'___',outFns{j},'_bar.png'));
    iter = iter + 1;
end

result