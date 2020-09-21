{
    "variables": {},
    "includes": [],
    "targets": [
        {
            "target_name": "tasks_addon",
            "type": "static_library",
            "dependencies": [ "tasks_lib", "<!(node -p \"require('node-addon-api').gyp\")" ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "src/addon"
            ],
            "sources": [
                # adds all .hpp/.cpp files directly under the './src/addon' directory
                "<!@(node -p \"require('fs').readdirSync('./src/addon').filter(p => p.endsWith('.cpp') || p.endsWith('.hpp')).map(p => 'src/addon/'+ p).join(' ')\")"
                # adds all .hpp/.cpp files directly under the './src/addon/include' directory
                "<!@(node -p \"require('fs').readdirSync('./src/addon/include').filter(p => p.endsWith('.cpp') || p.endsWith('.hpp')).map(p => 'src/addon/include/'+ p).join(' ')\")"
            ]
        },
        {
            "target_name": "tasks_lib",
            "type": "static_library",
            "include_dirs": [
                "src/tasks/include"
            ],
            "direct_dependent_settings": {
                "include_dirs": [
                    "src/tasks/include"
                ]
            },
            "sources": [
                # adds all .hpp/.cpp files directly under the './src/tasks' directory
                "<!@(node -p \"require('fs').readdirSync('./src/tasks').filter(p => p.endsWith('.cpp') || p.endsWith('.hpp')).map(p => 'src/tasks/'+ p).join(' ')\")",
                # adds all .hpp/.cpp files directly under the './src/tasks' directory
                "<!@(node -p \"require('fs').readdirSync('./src/tasks/include').filter(p => p.endsWith('.cpp') || p.endsWith('.hpp')).map(p => 'src/tasks/include/'+ p).join(' ')\")"
            ]
        }
        ],
    "conditions": []
}