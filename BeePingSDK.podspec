
Pod::Spec.new do |s|

  s.name         = "BeePingSDK"
  s.version      = "0.1.0"
  s.summary      = "ping sdk"
  s.description  = <<-DESC
    0.0.x:ping基础功能
    0.1.0:bitcode
                   DESC

  s.homepage     = "https://github.com/5hito/BeePingSDK"
  s.license      = {"type"=>"MIT", "file"=>"LICENSE"}
  s.author             = { "5hito" => "beemans@foxmail.com" }

  s.ios.deployment_target    = '8.0'
  s.source       = { :git => "https://github.com/5hito/BeePingSDK.git", :tag => s.version.to_s }

  s.requires_arc = true
  s.source_files = 'lib/Header/*.h'
  s.ios.vendored_libraries = 'lib/libBeePingSDK.a'

end
