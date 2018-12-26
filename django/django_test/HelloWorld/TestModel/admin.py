from django.contrib import admin
from TestModel.models import Test,Contact,Tag

class TagInline(admin.TabularInline):
    model = Tag

#diy管理界面
#管理页面的显示格式
class ContactAdmin(admin.ModelAdmin):
    # fields = ('name','email')  #定义了要显示的字段
    list_display = ('name','age','email')  #列表显示
    search_fields = ('name',)           #搜索记录关键字  （正则搜索）
    inlines = [TagInline]  #内联显示
    fieldsets = (
        ['Main',{'fields':('name','email'),}],
        ['Advance',{'classes':('collapse',),  #css布局
                    'fields':('age',),
                    }]
    )


admin.site.register(Contact,ContactAdmin)
admin.site.register([Test,Tag])
