;(function($){
	$.fn.uCarousel=function(o){
		return this.each(function(){
			var th=$(this)
				,_=th.data('uCarousel')||{
					axis:'x'
					,show:3
					,step:1
					,rows:1
					,curr:0
					,shift:0
					,itms:[]					
					,clickable:false					
					,retFalse:true
					,pageStep:3
					,duration:1000
					,easing:'swing'					
					,activeClass:'active'
					,buttonClass:'button'
					,blockAtEnd:true
					,fu:{
						pre:function(){							
							_.axis=_.axis=='x'							
							_.ul=$('>ul',_.me)
							_.ul=$('>ul',_.me)
								.css({
									position:'relative'
								})
							_.li=$('>li',_.ul)
								.css({
									display:'block'
									,position:'absolute'
								})
							_.li
								.each(function(n){
									_.itms[n]=$(this)
								})
								.eq(_.pos=_.n=_.curr).addClass(_.activeClass)
								
							_.liW=_.li.width()+parseInt(_.li.css('marginLeft'))+parseInt(_.li.css('marginRight'))
							_.liH=_.li.height()+parseInt(_.li.css('marginTop'))+parseInt(_.li.css('marginLeft'))
							
							_.ul
								.css({
									width:_.liW*Math.round(_.itms.length/_.rows)
									,height:_.liH*_.rows
								})
							
							for(var i=n=j=0;i<_.itms.length/_.rows;i++)
								for(j=0;j<_.rows;j++)
									if(n>=_.itms.length)
										break
									else
										_.itms[n++]
											.css({
												left:_.axis?i*_.liW:j*_.liW
												,top:_.axis?j*_.liH:i*_.liH
											})
							if(_.me.css('position')=='static')
								_.me.css({position:'relative'})
							_.me
								.css({
									width:_.axis?_.show*_.liW:_.liW*_.rows
									,height:_.axis?_.liH*_.rows:_.show*_.liH
									,overflow:'hidden'									
								})
								.states({
									states:{
										other:_.fu.change
									}
								})
							//_.pageStep=_.pageStep||_.show
						}
						,calc:function(n){
							n=n<_.itms.length
								?n>=0
									?n
									:_.blockAtEnd?0:_.itms.length-1
									:_.blockAtEnd?_.itms.length-1:0
						
							_.pos=n
							
							n=n-_.shift*_.rows>=0?n-_.shift*_.rows:0 
							
							if(n>_.itms.length-_.show*_.rows)
								n=_.itms.length-_.show*_.rows
							
							var pos={}
							_.axis
								?pos.left=-_.itms[n].prop('offsetLeft')
								:pos.top=-_.itms[n].prop('offsetTop')
							
							return pos
						}
						,change:function(n){
							if(_.n==n)
								return false
							
							_.prev=_.n
							
							_.pos=_.n=n<_.itms.length
								?n>=0
									?n
									:_.blockAtEnd?0:_.itms.length-1
									:_.blockAtEnd?_.itms.length-1:0
							
							_.li
								.removeClass(_.activeClass)
								.eq(_.n)
									.addClass(_.activeClass)
							
							_.fu.move(_.fu.calc(n))							
						}
						,move:function(pos){							
							_.ul
								.stop()
								.animate(pos,{
									duration:_.duration
									,easing:_.easing
								})
						}
						,buttons:function(){
							$('.'+_.buttonClass)
								.each(function(){
									var th=$(this)
										,type=th.data('type')									
									th
										.click(function(){
											swtch(type,{
												nextPage:function(){													
													_.fu.nextPage()
												}
												,prevPage:function(){
													_.fu.prevPage()
												}
												,next:function(){
													_.fu.next()
												}
												,prev:function(){
													_.fu.prev()
												}
												,"default":function(){}
											})()
											return false
										})									
								})							
						}
						,nextPage:function(){							
							var n,tmp
							n=_.pos+(_.pageStep||_.show)*_.rows
							n=_.pageStep&&n>(tmp=_.itms.length-_.show*_.rows)?tmp:n							
							_.fu.move(_.fu.calc(n))
						}
						,prevPage:function(){
							var n,tmp
							n=_.pos-(_.pageStep||_.show)*_.rows
							n=_.pageStep&&n<(tmp=_.show-_.show*_.rows)?tmp:n							
							_.fu.move(_.fu.calc(n))
						}
						,next:function(){							
							_.me.states(_.n+_.step)
						}
						,prev:function(){							
							_.me.states(_.n-_.step)
						}
						,clickable:function(){
							_.clickable&&
								_.li.each(function(n){
									var th=$(this)
										,a=$('a',th)									
									;(a.length?a:th)
										.click(function(){
											_.me.states(n)
											if(_.retFalse)
												return false
										})
								})
						}
					}
					,init:function(){
						_.me=th
							.data({uCarousel:_})
						_.fu.pre()
						_.fu.buttons()
						_.fu.clickable()
					}
				}
			swtch(typeof o,{
				object:function(){
					$.extend(true,_,o)
				}
				,string:function(){					
					swtch(o,{
						next:function(){
							_.fu.next()
						}
						,prev:function(){
							_.fu.prev()
						}
						,"default":function(){}
					})()
				}
				,number:function(){
					th.states(o)
				}
				,"function":function(){					
					_.me.on('_change',function(){
						o(_.n,_)
					})
				}
				,"default":function(){}
			})()
			_.me||_.init()
		})
	}
})(jQuery)

;(function($){
	$.fn.states=function(o,cb){
		return this.each(function(){
			var th=$(this)
				,_=th.data('states')||{
					event:'_change'
					,blockSame:true
					,states:{}
					,init:function(){						
						_.states['default']=_.states.other||function(){}													
						_.me=th
							.data({states:_})
							.bind(_.event,function(e,d){
								if(d==_.prev&&_.blockSame)
									return false
								swtch(d,_.states)(d)
							})
					}
				}
			swtch(typeof o,{
				object:function(){
					$.extend(true,_,o)
				}
				,string:function(){
					th.trigger(_.event,o)
				}
				,number:function(){					
					th.trigger(_.event,o)
				}
				,"default":function(){}
			})()
			_.me||_.init()
		})
	}
})(jQuery)

function swtch(arg,cases){	
	return	(typeof arg=='string'||typeof arg=='number')
		?cases[arg]
			?cases[arg]
			:cases['default']||arg
		:typeof arg=='object'
			?(function(){
				var ret=arg instanceof Array?[]:{}
					,i
				if(arg.constructor===RegExp)
					for(i in cases)
						cases.hasOwnProperty(i)&&arg.test(i)&&(ret[i]=cases[i])
				else
					for(i in arg)
						if(arg.hasOwnProperty(i))
							ret[i]=swtch(arg[i],cases)
				return ret
			})()
			:typeof arg=='function'
				?swtch(arg(),cases)
				:arg
}