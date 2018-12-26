from pyecharts import Bar

bar = Bar("title","Secondtitle")
bar.use_theme('dark')
bar.add("code",['java','python','html','css','javaScript'],[50,70,40,40,60])

bar.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\2.html')