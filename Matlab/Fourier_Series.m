function signal_system_project()
    % Şekil ve eksenler oluştur
    fig = figure('Position', [100, 100, 1500, 900]);

    % Girdi alma alanı
    panel_input = uipanel('Title','Girdiler','Position',[0.01 0.76 0.98 0.20]);

    % Girdi kutuları ve etiketleri
    uicontrol(panel_input,'Style','text','Position',[130 150 120 20],'String','1. Fonksiyon (A1, f1, θ1)');
    uicontrol(panel_input,'Style','edit','Position',[250 150 50 20],'Tag','A1','String','1');
    uicontrol(panel_input,'Style','edit','Position',[310 150 50 20],'Tag','f1','String','1');
    uicontrol(panel_input,'Style','edit','Position',[370 150 50 20],'Tag','theta1','String','0');

    uicontrol(panel_input,'Style','text','Position',[130 120 120 20],'String','2. Fonksiyon (A2, f2, θ2)');
    uicontrol(panel_input,'Style','edit','Position',[250 120 50 20],'Tag','A2','String','1');
    uicontrol(panel_input,'Style','edit','Position',[310 120 50 20],'Tag','f2','String','2');
    uicontrol(panel_input,'Style','edit','Position',[370 120 50 20],'Tag','theta2','String','0');

    uicontrol(panel_input,'Style','text','Position',[130 90 120 20],'String','3. Fonksiyon (A3, f3, θ3)');
    uicontrol(panel_input,'Style','edit','Position',[250 90 50 20],'Tag','A3','String','1');
    uicontrol(panel_input,'Style','edit','Position',[310 90 50 20],'Tag','f3','String','3');
    uicontrol(panel_input,'Style','edit','Position',[370 90 50 20],'Tag','theta3','String','0');

    uicontrol(panel_input,'Style','text','Position',[10 60 800 20],'String','Fourier Serisi  ( a0 , a1 , b1 , a2 , b2 , a3 , b3 , w0 , T )');
    uicontrol(panel_input,'Style','edit','Position',[130 30 50 20],'Tag','a0','String','0');
    uicontrol(panel_input,'Style','edit','Position',[190 30 50 20],'Tag','a1','String','1');
    uicontrol(panel_input,'Style','edit','Position',[250 30 50 20],'Tag','b1','String','0');
    uicontrol(panel_input,'Style','edit','Position',[310 30 50 20],'Tag','a2','String','0');
    uicontrol(panel_input,'Style','edit','Position',[370 30 50 20],'Tag','b2','String','1');
    uicontrol(panel_input,'Style','edit','Position',[430 30 50 20],'Tag','a3','String','0');
    uicontrol(panel_input,'Style','edit','Position',[490 30 50 20],'Tag','b3','String','0');
    uicontrol(panel_input,'Style','edit','Position',[550 30 50 20],'Tag','w0','String','1');
    uicontrol(panel_input,'Style','edit','Position',[610 30 50 20],'Tag','T','String','1');

    % Buton
    uicontrol(panel_input,'Style','pushbutton','Position',[700 30 70 25],'String','Çiz','Callback',@plot_graphs);

    % Çizim alanı
    panel_plot = uipanel('Title','Çizimler','Position',[0.01 0.01 0.98 0.75]);

    % Sinyal 1 - Sin
    subplot(5, 3, 1, 'Parent', panel_plot);
    title('Sin1: A1 * sin(2πf1t + θ1)');

    % Sinyal 1 - Cos
    subplot(5, 3, 4, 'Parent', panel_plot);
    title('Cos1: A1 * cos(2πf1t + θ1)');

    % Sinyal 2 - Sin
    subplot(5, 3, 2, 'Parent', panel_plot);
    title('Sin2: A2 * sin(2πf2t + θ2)');

    % Sinyal 2 - Cos
    subplot(5, 3, 5, 'Parent', panel_plot);
    title('Cos2: A2 * cos(2πf2t + θ2)');

    % Sinyal 3 - Sin
    subplot(5, 3, 3, 'Parent', panel_plot);
    title('Sin3: A3 * sin(2πf3t + θ3)');

    % Sinyal 3 - Cos
    subplot(5, 3, 6, 'Parent', panel_plot);
    title('Cos3: A3 * cos(2πf3t + θ3)');

    % Toplam Sin ve Cos
    subplot(5, 3, [7, 8, 9], 'Parent', panel_plot);
    title('Toplam Sin ve Cos: sin1 + cos1 + sin2 + cos2 + sin3 + cos3');

    % Fourier toplam sinyal
    subplot(5, 3, [10,11,12], 'Parent', panel_plot);
    title('Fourier Sonuç:');

    function plot_graphs(~, ~)
        % Girdi değerlerini al
        A1 = str2double(findobj(panel_input,'Tag','A1').String);
        f1 = str2double(findobj(panel_input,'Tag','f1').String);
        theta1 = str2double(findobj(panel_input,'Tag','theta1').String);
        A2 = str2double(findobj(panel_input,'Tag','A2').String);
        f2 = str2double(findobj(panel_input,'Tag','f2').String);
        theta2 = str2double(findobj(panel_input,'Tag','theta2').String);
        A3 = str2double(findobj(panel_input,'Tag','A3').String);
        f3 = str2double(findobj(panel_input,'Tag','f3').String);
        theta3 = str2double(findobj(panel_input,'Tag','theta3').String);
        a0 = str2double(findobj(panel_input,'Tag','a0').String);
        a1 = str2double(findobj(panel_input,'Tag','a1').String);
        b1 = str2double(findobj(panel_input,'Tag','b1').String);
        a2 = str2double(findobj(panel_input,'Tag','a2').String);
        b2 = str2double(findobj(panel_input,'Tag','b2').String);
        a3 = str2double(findobj(panel_input,'Tag','a3').String);
        b3 = str2double(findobj(panel_input,'Tag','b3').String);
        w0 = str2double(findobj(panel_input,'Tag','w0').String);
        T = str2double(findobj(panel_input,'Tag','T').String);
        
        % Zaman vektörü oluştur - Sinyaller için
        t = linspace(0, 1, 1000);

        % Sinyalleri oluştur - Sinyaller için
        sin1 = A1 * sin(2 * pi * f1 * t + theta1);
        cos1 = A1 * cos(2 * pi * f1 * t + theta1);
        sin2 = A2 * sin(2 * pi * f2 * t + theta2);
        cos2 = A2 * cos(2 * pi * f2 * t + theta2);
        sin3 = A3 * sin(2 * pi * f3 * t + theta3);
        cos3 = A3 * cos(2 * pi * f3 * t + theta3);
    
        total_signal = sin1 + cos1 + sin2 + cos2 + sin3 + cos3;
    
        % Zaman vektörü oluştur - Fourier için
        t_fourier = linspace(0, 10*T, 1000);
    
        % Sinüzoidal işaretlerin oluşturulması - Fourier için
        x1 = a0 + a1*cos(w0*t_fourier) + b1*sin(w0*t_fourier);
        x2 = a0 + a2*cos(2*w0*t_fourier) + b2*sin(2*w0*t_fourier);
        x3 = a0 + a3*cos(3*w0*t_fourier) + b3*sin(3*w0*t_fourier);
    
        x_total = x1 + x2 + x3;
    
        % Güncellenmiş grafikleri çizdiğim yer
        % Sin1
        subplot(5, 3, 1);
        plot(t, sin1);
        title('Sin1: A1 * sin(2πf1t + θ1)');
    
        % Cos1
        subplot(5, 3, 4);
        plot(t, cos1);
        title('Cos1: A1 * cos(2πf1t + θ1)');
    
        % Sin2
        subplot(5, 3, 2);
        plot(t, sin2);
        title('Sin2: A2 * sin(2πf2t + θ2)');
    
        % Cos2
        subplot(5, 3, 5);
        plot(t, cos2);
        title('Cos2: A2 * cos(2πf2t + θ2)');
    
        % Sin3
        subplot(5, 3, 3);
        plot(t, sin3);
        title('Sin3: A3 * sin(2πf3t + θ3)');
    
        % Cos3
        subplot(5, 3, 6);
        plot(t, cos3);
        title('Cos3: A3 * cos(2πf3t + θ3)');
    
        % Toplam Sin ve Cos
        subplot(5, 3, [7, 8, 9]);
        plot(t, total_signal);
        title('Toplam Sin ve Cos: sin1 + cos1 + sin2 + cos2 + sin3 + cos3');
    
        % Fourier toplam sinyal
        subplot(5, 3, [10, 11, 12]);
        plot(t_fourier, x_total);
        title('Fourier Sonuç:');
    end
end

